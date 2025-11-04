#include <stdio.h>

int N, M;
int arr[9];

void dfs(int depth, int start){
    if(depth == M){
        for(int i = 0; i < M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i = start; i <= N; i++){
        arr[depth] = i;
        dfs(depth + 1, i);
    }
}

int main(void){
    scanf("%d %d", &N, &M);
    dfs(0, 1);
    return 0;
}