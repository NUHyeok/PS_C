#include <stdio.h>

typedef struct Graph{
    int n;
    int adj[100][100];
}Graph;

void floyd_warshall(Graph *g){
    for(int k = 0; k < g->n; k++){
        for(int i = 0; i < g->n; i++){
            for(int j = 0; j < g->n; j++){
                if(g->adj[i][k] == 1 && g->adj[k][j] == 1){
                    g->adj[i][j] = 1;
                }
            }
        }
    }
}



int main(void){
    Graph g;
    scanf("%d", &g.n);
    

    for(int i = 0; i < g.n; i++){
        for(int j = 0; j < g.n; j++){
            scanf("%d", &g.adj[i][j]);
        }
    }

    floyd_warshall(&g);

    for(int i = 0; i < g.n; i++){
        for(int j = 0; j <g.n; j++){
            printf("%d ", g.adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}