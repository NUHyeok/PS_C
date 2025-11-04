#include <stdio.h>
#include <stdlib.h>

int N, M;
int arr[9];
int visited[9];

int compare(const int* a, const int *b){
    return (*a - *b);
}

void dfs(int depth, int *nums){
    if (depth == M){
        for(int i = 0; i < M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    int last_num = -1;

    for(int i = 0; i < N; i++){
        if(last_num == nums[i]) continue;
        if(visited[i]) continue;

        last_num = nums[i];
        arr[depth] = nums[i];
        visited[i] = 1;
        dfs(depth + 1, nums);
        visited[i] = 0;

    }
}


int main(void){
    scanf("%d %d", &N, &M);
    int *A = (int *)malloc(N * sizeof(int));

    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    qsort(A, N, sizeof(int), compare);
    dfs(0, A);
    free(A);
    return 0;
}