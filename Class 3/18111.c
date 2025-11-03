#include <stdio.h>
#include <limits.h>

int space[500][500];
int height[257];

int calculate_time(int height, int N, int M, int B){
    int block = B;
    int time = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (space[i][j] < height){
                time += (height - space[i][j]);
                block -= (height - space[i][j]);
            }
            else if(space[i][j] > height){
                time += 2 * (space[i][j] - height);
                block += (space[i][j] - height);
            }
        }
    }

    if(block >= 0) return time;
    else return -1;
}

int main(void){
    int N, M, B;
    scanf("%d %d %d", &N, &M, &B);
    int min_time = INT_MAX;
    int height;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &space[i][j]);
        }
    }

    for(int i = 0; i <= 256; i++){
        int time = calculate_time(i, N, M, B);
        if(time != -1 && min_time >= time) {
            min_time = time;
            height = i;
        }
    }
    printf("%d %d", min_time, height);
    return 0;
}