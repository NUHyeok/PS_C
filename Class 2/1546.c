#include <stdio.h>
#include <stdlib.h>

int main(void){
    int best = 0, N;
    double sum = 0;
    scanf("%d", &N);

    int* A = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++){
        scanf("%d", &A[i]);
        if(A[i] > best) best = A[i];
    }

    for (int i = 0; i < N; i++){
        sum += (((double)A[i] / best) * 100);
    }
    free(A);

    printf("%f", sum / N);

    return 0;
}