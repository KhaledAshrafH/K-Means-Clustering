# K-Means-Clustering
OpenMP Program to partition n observations into k clusters in which each observation belongs to the cluster with the nearest mean.
# Requirements
<ul>
<li>Read The data file => <b>Main Thread</b></li>
<li>Initiate 2 random numbers for each thread/cluster.the 2 random numbers are representing (x, y) initial of cluster centroid => <b>Main Thread</b></li>
<li>Calculate the distance between each point and cluster centroid.using the Euclidean distance formula  => <b>Forked Threads</b></li>
<li>Filter each point distances depending on minimum value => <b>Main Thread</b></li>
<li>Calculate the mean for each cluster as new cluster centroid => <b>Forked Threads</b></li>
<li>Repeat steps 3 to 5 with the new cluster centroid until the ending criteria you specified.</li>
</ul>

