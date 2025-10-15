#include <stdio.h>

int M, N; // 가로(M), 세로(N)
int P[50][50];
int visited[50][50];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int y, int x){
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++){
        int yy = y + dy[i];
        int xx = x + dx[i];

        if(xx < 0 || xx >= M || yy < 0 || yy >= N){
            continue;
        }
        if(P[yy][xx] == 1 && visited[yy][xx] == 0){
            dfs(yy,xx);
        }
    }
}

void reset(){
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            P[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

int main(void){
    int T;
    scanf("%d", &T);
    

    while(T--){
        int K;
        reset();
        scanf("%d %d %d", &M, &N, &K);
        while(K--){
            int a,b;
            scanf("%d %d", &a, &b);
            P[b][a] = 1;
        }

        int count  = 0;

        for (int i = 0; i < N; i++) { 
            for (int j = 0; j < M; j++) { 
                if (P[i][j] == 1 && visited[i][j] == 0) {
                    dfs(i, j); 
                    count++;   
                }
            }
        }

        printf("%d\n", count);
    }
    return 0;
}