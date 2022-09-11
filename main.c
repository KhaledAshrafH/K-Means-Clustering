#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
//2D point.
struct point
{
    double x, y;
};
double distanceBetween2Points(double x1,double x2,double y1,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

}
void random_shuffle(int *arr, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = arr[j];
          arr[j] = arr[i];
          arr[i] = t;
        }
    }
}
int main(int argc, char *argv[])
{
    FILE *file = fopen("points.txt", "r");
    int i,countPoints=0,j=0;
    char line[100];
    int allArry[1000];
    struct point points[100];
    int check;
    //get the data from the file and store it into points array.~1
    while (fscanf(file, "%s", line)!=EOF)
    {
        allArry[j]= atoi ((char *)line);
        if (j%2!=0)
        {
            points[countPoints].y=allArry[j];
            points[countPoints].x=allArry[j-1];
            countPoints+=1;
        }
        j++;
    }
    int np;
    //get the no. of threads.
    #pragma omp parallel
    {
        np = omp_get_num_threads();
    }
    //if the no of threads some how become more than the points counts make it equal
    //to have no of clusters equal threads.
    if(np>countPoints)np=countPoints;
    struct point centroid[np];
    //shuffle the points randomly.
    int p[countPoints];
    for(j = 0; j < countPoints; j++) p[j]=j;
    random_shuffle(p,countPoints);
    //get the random centroids(based on first k points).~2
    for( i=0; i<np; i++)
    {
        centroid[i].x=points[p[i]].x;
        centroid[i].y=points[p[i]].y;
    }
    /*for(i=0;i<np;i++){
        printf("(%f,%f)\n",centroid[i].x,centroid[i].y);
    }*/
    //declare an array to store the distance(error) between every point with every cluster.
    double diff[np][countPoints];
    //carry which point with which cluster.
    int filteredClusters[countPoints];
    int k;
    ///iteration loop.
    for(k=0; k<7; k++)
    {   // Calculate the distance between each point and cluster centroid.~3
        #pragma omp parallel private(i)
        {
            #pragma omp for schedule(static)
            for ( i = 0; i < np; i++)
            {
                for(j=0; j<countPoints; j++)
                {
                    diff[i][j]=distanceBetween2Points(points[j].x,centroid[i].x,points[j].y,centroid[i].y);
                }
            }
        }
        double min;
        int minIndx;
        ///main thread.
        //Filter each point distances depending on minimum value.~4
        for(j=0; j<countPoints; j++)
        {
            min=1e9;
            for(i=0; i<np; i++)
            {
                if(diff[i][j]<=min)
                {
                    min=diff[i][j];
                    minIndx=i;
                }
            }
            filteredClusters[j]=minIndx;

        }
        //store the centroid.
        struct point oldcentroid[np];
        for(i=0; i<np; i++)
        {
            oldcentroid[i].x=centroid[i].x;
            oldcentroid[i].y=centroid[i].y;
        }
        //Calculate the mean for each cluster as new cluster centroid.~5
        double x=0,y=0,count=0;
        #pragma omp parallel private(i,x,y,count)
        {
            #pragma omp for schedule(static)
            for ( i = 0; i < np; i++)
            {
                x=0,y=0,count=0;
                for(j=0; j<countPoints; j++)
                {
                    if(filteredClusters[j]==i)
                    {
                        x+=points[j].x;
                        y+=points[j].y;
                        count++;
                    }

                }
                centroid[i].x=x/count;
                centroid[i].y=y/count;
            }

        }
        //stop if  the threshold of centroid difference error =0(oldCentroid=centroid).
        check=0;
        for(i=0; i<np; i++)
        {
            if(centroid[i].x!=oldcentroid[i].x||centroid[i].y!=oldcentroid[i].y) check=1;
        }
        if(!check)break;
    }
    //The program output.
    for(i=0; i<np; i++)
    {
        printf("Cluster %d:\n",i+1);
        for(j=0; j<countPoints; j++)
        {
            if(filteredClusters[j]==i)
            {
                printf("(%d,%d)\n",(int)points[j].x,(int)points[j].y);

            }

        }
    }

}