#include <stdio.h>

int N, M;
int front, rear;
int road[100][100];
int time[100][100];
int visited[100][100];

typedef struct {
    int x;
    int y;
}Queue;

Queue queue[10000];

void push(int x, int y){
    visited[x][y] = 1;
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

Queue pop(){
    return queue[front++];
}

int is_empty(){
    return front == rear;
}

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(){
    push(0,0);

    while(!is_empty()){
        Queue current = pop();
        int x = current.x;
        int y = current.y;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
            if (visited[nx][ny] || road[nx][ny] == 0) continue;
            time[nx][ny] = time[x][y] + 1;
            push(nx,ny);
        }

    }
}

int main(void){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &road[i][j]);
        }
    }
    time[0][0] = 1;
    bfs();
    printf("%d", time[N-1][M-1]);
    return 0;
}