#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N, M;
    int max = 0;
    int is = 0;
    scanf("%d %d", &N, &M);
    int *A = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N - 2; i++){
        for (int j = i+1; j < N -1; j++){
            for(int k = j+1; k < N; k++){
                if(A[i] + A[j] + A[k] > max && A[i] + A[j] + A[k] <= M) max = A[i] + A[j] + A[k];
                if (max == M) {
                    is = 1;
                    break;
                }
            }
            if(is) break;
        }
        if(is) break;
    }
    free(A);

    printf("%d", max);
    return 0;

}