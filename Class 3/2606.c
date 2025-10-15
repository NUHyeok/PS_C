#include <stdio.h>

int N, T;
int graph[101][101] = {0};
int visited[101] = {0};
int count = 0;

void dfs(int Node){
    visited[Node] = 1;
    count ++;

    for(int i = 1; i <= N; i++){
        if(graph[Node][i] == 1 && visited[i] == 0) dfs(i);
    }
}

int main(void){
    scanf("%d %d", &N, &T);

    for(int i = 0; i < T; i++){
        int a,b;
        scanf("%d %d", &a, &b);

        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(1);

    printf("%d", count -1);
    return 0;
}