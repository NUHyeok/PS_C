#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        int k, n;
        scanf("%d %d", &k, &n);

        int **A = malloc((k+1) * sizeof(int *));
        for(int j = 0; j < k+1; j++){
            A[j] = malloc((n+1) * sizeof(int));
        }

        for(int j = 0; j < k+1; j++){
            for(int z = 0; z < n+1; z++){
                if(z == 0) continue;

                if(j == 0) A[j][z] = z;
                else if(z == 1) A[j][z] = A[j-1][z];
                else{
                    A[j][z] = A[j-1][z] + A[j][z-1];
                }
            }
        }

        printf("%d\n", A[k][n]);
        free(A);
    }

    return 0;
}