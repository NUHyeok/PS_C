#include <stdio.h>
#include <stdlib.h>

int N, M;
int arr[9];
int visited[9];

int compare(const int* a, const int* b){
    return (*a - *b);

// 백트래킹

}
void dfs(int depth, int *num){
    if(depth == M){
        for (int i = 0; i < M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 0; i < N; i++){
        if(!visited[i]){
            visited[i] = 1;
            arr[depth] = num[i];
            dfs(depth + 1, num);
            visited[i] = 0;
        }
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
    return 0;
}