#include <stdio.h>
#include <string.h>

int Edge[101][101];

int bfs(int start, int target, int size){
    int queue[101];
    int front = 0, rear = 0;

    int distance[101];
    memset(distance, -1, sizeof(distance));

    queue[rear++] = start;
    distance[start] = 0;

    while(front < rear){
        int current = queue[front++];

        if (current == target){
            return distance[current];
        }
        for(int i = 1; i <= size; i++){
            if(Edge[current][i] && distance[i] == -1){
                distance[i] = distance[current] + 1;
                queue[rear++] = i;
            }
        }
    }
    return -1;
}

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int a,b;
        scanf("%d %d", &a, &b);

        Edge[a][b] = 1;
        Edge[b][a] = 1;
    }

    int min = 9999999;
    int person;


    for(int i = 1; i <= N; i++){
        int current = 0;
        for(int j = 1; j <= N; j++){
            if(i==j) continue;
            current += bfs(i, j, N);
        }
        if(current < min){
            min = current;
            person = i;
        }
    }

    printf("%d\n", person);
    return 0;

    


}