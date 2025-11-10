#include <stdio.h>

int N,M;
char A[600][600];
int visited[600][600];
int cnt;

void dfs(int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= M) return;
    else if(visited[x][y]) return;
    else if(A[x][y] == 'X') {
        visited[x][y] = 1;
        return;
    }
    else if(A[x][y] == 'P'){
        visited[x][y] = 1;
        cnt++;
        dfs(x+1,y);
        dfs(x, y+1);
        dfs(x-1,y);
        dfs(x, y-1);
    }
    else{
        visited[x][y] = 1;
        dfs(x+1,y);
        dfs(x, y+1);
        dfs(x-1,y);
        dfs(x, y-1);
    }
}

int main(void){
    scanf("%d %d", &N, &M);
    int index1,index2;

    for(int i = 0; i < N; i++){
        for(int j= 0; j < M; j++){
            scanf(" %c", &A[i][j]);
            if(A[i][j] == 'I'){
                index1 = i;
                index2 = j;
            }
        }
    }
    dfs(index1,index2);
    if(cnt > 0) printf("%d", cnt);
    else printf("TT");
    return 0;
}