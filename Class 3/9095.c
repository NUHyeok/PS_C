#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        int s;
        scanf("%d", &s);
        int *A = (int *)malloc((s+1) * sizeof(int));
        A[1] = 1;
        A[2] = 2;
        A[3] = 4;

        for(int j = 4; j < s+1; j++){
            A[j] = A[j-1] + A[j-2] + A[j-3];
        }

        printf("%d\n", A[s]);
        free(A);
    }
}