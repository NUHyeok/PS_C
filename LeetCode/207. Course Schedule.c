bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int* indegree = (int *)calloc(numCourses, sizeof(int));
    int *outdegree = (int *)calloc(numCourses, sizeof(int));

    int* queue = (int *)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    for(int i = 0; i < prerequisitesSize; i++){
        int next = prerequisites[i][0];
        int pre = prerequisites[i][1];

        indegree[next]++;
        outdegree[pre]++;
    }

    int** adj = (int**)malloc(sizeof(int*) * numCourses);
    for (int i = 0; i < numCourses; i++) {
        if (outdegree[i] > 0) {
            adj[i] = (int*)malloc(sizeof(int) * outdegree[i]);
        } else {
            adj[i] = NULL;
        }
    }
}