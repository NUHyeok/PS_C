#include <stdio.h>

int checked[1001];
int Edge[1001][1001];

void dfs(int N, int size){
    if(!checked[N]){
        checked[N] = 1;
        for(int i = 1; i <= size; i++){
            if(Edge[N][i]) {
                dfs(i, size);
            }
        }
    }
    else{
        return;
    }
}

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        Edge[a][b] = 1;
        Edge[b][a] = 1;
    }

    int count = 0;

    for(int i = 1; i <= N; i++){
        if(!checked[i]){
            count++;
            dfs(i, N);
        }
    }
    printf("%d", count);
    return 0;
}