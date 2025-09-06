#include <stdio.h>
#include <stdlib.h>

int main(void){
    int max = -1000000;
    int min = 1000000;

    int N;
    scanf("%d", &N);

    int *A = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++){
        scanf("%d", &A[i]);
        if (A[i] > max){
            max = A[i];
        }

        if (A[i] < min){
            min = A[i];
        }
    }

    free(A);

    printf("%d %d", min, max);
    return 0;
}