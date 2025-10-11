#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int main(void){
    int N;
    int sum = 0;
    int time[1001] = {0};
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &time[i]);
    }

    qsort(time, N, sizeof(int), compare);

    for(int i = 0; i < N; i++){
        sum += time[i];
        time[i+1] += time[i];
    }

    printf("%d", sum);
    return 0;

}