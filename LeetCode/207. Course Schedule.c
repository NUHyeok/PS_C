int num_pre[2000];

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    memset(num_pre, 0, sizeof(num_pre));

    for(int i = 0; i < prerequisitesSize; i++){
        num_pre[prerequisites[i][0]]++;
    }

    int count = 0;

    while(count < numCourses){
        int i = 0;
        for(; i < numCourses; i++){
            if(num_pre[i] == 0) break;
        }
        if(i == numCourses) return false;

        num_pre[i] = -1;
        count++;

        for(int j = 0; j < prerequisitesSize; j++){
            if(prerequisites[j][1] == i) num_pre[prerequisites[j][0]]--;
        }
    }
    return true;
}