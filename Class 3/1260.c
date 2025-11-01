#include <stdio.h>

int edge[1001][1001];
int checked[1001];
void dfs(int V,int N){
    if(!checked[V]){
        checked[V] = 1;
        printf("%d ", V);
        for(int i = 1; i <= N; i++) {
            if(edge[V][i]) dfs(i, N);
        }
    }
}

int Queue[1001];
int checked_bfs[1001];

void bfs(int V,int N){
    int front = 0;
    int rear = 0;
    int pop;

    Queue[rear++] = V;
    checked_bfs[V] = 1;
    printf("%d ", V);

    while(front < rear){
        pop = Queue[front++];

        for(int i = 1; i <= N; i++){
            if(edge[pop][i] == 1 && !checked_bfs[i]){
                checked_bfs[i] = 1;
                printf("%d ", i);
                Queue[rear++] = i;
            }
        }

    }

}

int main(void){
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);

    for(int i = 0; i < M; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        edge[a][b] = 1;
        edge[b][a] = 1;
    }

    dfs(V,N);
    printf("\n");
    bfs(V,N);

    return 0;

}