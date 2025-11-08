#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int start;
    int end;
}Time;

int compare(const void *a, const void *b){
    Time *timeA = (Time *)a;
    Time *timeB = (Time *)b;

    if(timeA ->end < timeB ->end) return -1;
    else if (timeA->end > timeB->end) return 1;
    else{
        if(timeA->start < timeB->start) return -1;
        else return 1;
    }
}

int main(void){
    int N;
    scanf("%d", &N);
    Time *A = (Time *)malloc(N * sizeof(Time));

    for(int i = 0; i < N; i++){
        scanf("%d %d", &A[i].start, &A[i].end);
    }

    qsort(A, N, sizeof(Time), compare);

    int last_end_time = 0;
    int count = 0;

    for(int i = 0; i < N; i++){
        if(A[i].start >= last_end_time){
            count++;
            last_end_time = A[i].end;
        }
    }

    printf("%d", count);


    return 0;
}