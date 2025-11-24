#include <stdio.h>

typedef struct Queue{
    int x;
    int y;
}Queue;

Queue queue[1000000];

int road[1001][1001];
int visited[1001][1001];
int time[1001][1001];
int front, rear;
int a,b;


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

void bfs(int x, int y){
    push(x,y);

    while(!is_empty()){
        Queue current = pop();
        int x = current.x;
        int y = current.y;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (ny < 0 || nx < 0 || ny >= b || nx >= a) continue;
            if (visited[nx][ny] || road[nx][ny] == 0) continue;
            time[nx][ny] = time[x][y] + 1;
            push(nx,ny);
        }

    }
}
int main(void){
    int start_x, start_y;
    scanf("%d %d", &a, &b);
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            scanf("%d", &road[i][j]);
            if(road[i][j] == 2){
                start_x = i;
                start_y = j;
            }
        }
    }

    bfs(start_x, start_y);

    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            if(road[i][j] == 0) printf("0 ");
            else if(visited[i][j]) printf("%d ", time[i][j]);
            else printf("-1 ");
        }
        printf("\n");
    }

    return 0;
}