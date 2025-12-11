#include <stdio.h>
#include <string.h>
#define min(x,y) (((x) > (y)) ? (y) : (x))

int adj[1001][1001];

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = 1000000;
        }
    }

    int dp[1001];
    memset(dp, 100000, sizeof(dp));

    int start, end, cost;

    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &start, &end, &cost);
        if(adj[start][end] > cost) adj[start][end] = cost;
    }

    scanf("%d %d", &start, &end);

    for(int i = 1; i <= N; i++)
    return 0;


}