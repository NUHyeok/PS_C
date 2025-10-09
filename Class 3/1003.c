#include <stdio.h>
#include <stdlib.h>


int main(void){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        int s;
        scanf("%d", &s);
        int **A = (int **)malloc((s+1) * sizeof(int *));

        A[0] = (int *)malloc(2 * sizeof(int));
        A[1] = (int *)malloc(2 * sizeof(int));
        A[0][0] = 1;
        A[0][1] = 0;
        A[1][0] = 0;
        A[1][1] = 1;

        for (int i =  2; i < s+1; i++){
            A[i] = (int *)malloc(2 * sizeof(int));
            A[i][0] = A[i-1][0] + A[i-2][0];
            A[i][1] = A[i-1][1] + A[i-2][1];
        }

        printf("%d %d\n", A[s][0], A[s][1]);
        for (int i = 0; i < s+1; i++){
            free(A[i]);
        }
        free(A);
        }

}


