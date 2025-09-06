#include <stdio.h>
#include <stdlib.h>


int main(void){
    int N, X;
    scanf("%d %d", &N, &X);
    
    int *A = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++){
        scanf("%d", &A[i]);
        if (A[i] < X){
            printf("%d ", A[i]);
        }
    }

    free(A);
    return 0;
}