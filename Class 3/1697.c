#include <stdio.h>

int N, K;
int time[100001];
int Queue[100001];
int front = 0;
int rear = 0;

void bfs(){
    Queue[rear++] = N;
    time[N] = 0;

    while(front < rear){
        int current = Queue[front++];

        if(current == K){
            printf("%d", time[K]);
            return;
        }

        int next_pos1 = current - 1;
        if(next_pos1 >= 0 && next_pos1 <= 100000 && time[next_pos1] == -1){
            time[next_pos1] = time[current] + 1;
            Queue[rear++] = next_pos1;
        } 

        int next_pos2 = current + 1;
        if(next_pos2 >= 0 && next_pos2 <= 100000 && time[next_pos2] == -1){
            time[next_pos2] = time[current] + 1;
            Queue[rear++] = next_pos2;
        } 

        int next_pos3 = 2 * current;
        if(next_pos3 >= 0 && next_pos3 <= 100000 && time[next_pos3] == -1){
            time[next_pos3] = time[current] + 1;
            Queue[rear++] = next_pos3;
        } 

    }
    
}

int main(void){
    scanf("%d %d", &N, &K);
    memset(time, -1, sizeof(time));
    bfs();
    return 0;

}