#include <stdio.h>
#define Max(x,y) ((x) > (y))? (x) : (y)

int triangle[500][500];

int main(void){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            scanf("%d", &triangle[i][j]);
        }
    }

    for(int i = 1; i < N; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) triangle[i][j] += triangle[i-1][j];
            else if(j == i) triangle[i][j] += triangle[i-1][j-1];
            else triangle[i][j] += Max(triangle[i-1][j], triangle[i-1][j-1]);
        }
    }
    int max = 0;
    for(int j = 0; j < N; j++){
        max = Max(max, triangle[N-1][j]);
    }

    printf("%d", max);
    return 0;
}