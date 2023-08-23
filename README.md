# K-Means Clustering Algorithm

This OpenMP program implements the K-means clustering algorithm using OpenMP APIs. The K-means algorithm is a popular method of vector quantization that aims to partition n observations into k clusters. Each observation is assigned to the cluster with the nearest mean, serving as a prototype of the cluster.

## Application and Use Cases

The K-means algorithm finds applications in various domains, including:

- **Market Segmentation**: Identifying distinct groups of customers based on their purchasing behavior and preferences.
- **Document Clustering**: Grouping similar documents together based on their content to aid in information retrieval and text mining.
- **Image Segmentation**: Dividing an image into meaningful regions or objects based on color, texture, or other visual features.
- **Image Compression**: Reducing the size of an image by representing it using a smaller number of cluster centroids.

## Algorithm Overview

The K-means algorithm follows these steps:

1. **Specify the number of clusters, K**: Determine the desired number of clusters to partition the data.
2. **Initialize centroids**: Randomly select K data points as the initial cluster centroids.
3. **Iterate until convergence**:
   - **Assign data points to clusters**: Calculate the distance between each data point and the cluster centroids. Assign each data point to the cluster with the closest centroid.
   - **Update cluster centroids**: Recalculate the centroids by taking the average of all data points assigned to each cluster.
   - **Check for convergence**: Repeat the above steps until the centroids no longer change significantly or a maximum number of iterations is reached.

## Distance Calculation

The Euclidean distance formula is used to calculate the distance between a data point and its closest centroid. Given two points (x1, y1) and (x2, y2), the Euclidean distance is computed as:
```
distance = sqrt((x1 - x2)^2 + (y1 - y2)^2)
```

## Requirements

To run the program, the following requirements should be met:

1. **Known number of data points**: The number of data points to be clustered should be known in advance.
2. **Data points in 2 dimensions**: The data points should be represented as (x, y) coordinates in a 2-dimensional space.
3. **OpenMP APIs only**: The program should use only OpenMP APIs for parallel computing and not MPI APIs.
4. **Read data points from a file**: The program should read the data points from a file named "points.txt" within the C script. The format of the file should have each data point on a separate line.
5. **Program output**: The program should display the clusters and their corresponding data points in the following format:
```
  Cluster 1:
  (x1, y1)
  (x2, y2)
  ...
```

6. **Number of threads**: The number of threads used should be equal to the number of clusters specified when running the program.
7. **Stopping criteria**: The program should allow flexibility in choosing the maximum number of iterations or a threshold for the centroid difference error to determine convergence.

## Usage

Follow these steps to use the program:

1. **Compile the program**: Use a C compiler that supports OpenMP to compile the program.
2. **Prepare the data file**: Create a file named "points.txt" and populate it with the data points to be clustered. Each data point should be on a separate line, with the x and y coordinates separated by a space or comma.
3. **Run the program**: Execute the compiled program.
4. **Observe the output**: The program will display the clusters and their corresponding data points in the console.

Note: Ensure that the number of clusters specified when running the program matches the desired number of clusters for partitioning the data.


## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvement, please open an issue or submit a pull request.


## Authors

- [Khaled Ashraf Hanafy Mahmoud - 20190186](https://github.com/KhaledAshrafH).
- [Ahmed Sayed Hassan Youssef - 20190034](https://github.com/AhmedSayed117).
- [Samah Moustafa Hussien Mahmoud - 20190248](https://github.com/Samah-20190248).

## License

This program is licensed under the [MIT License](LICENSE.md).
