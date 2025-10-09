#include <stdio.h>
#include <stdlib.h>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

int main(void){
    int N;
    scanf("%d", &N);

    int *A = (int *)malloc((N+1) * sizeof(int));
    A[1] = 0;
    A[2] = 1;
    A[3] = 1;

    for(int i = 4; i < N+1; i++){
        int s = 0;
        if(i % 3 == 0) s = A[i/3] + 1;
        if(i % 2 == 0) {
            if(s > 0) s = MIN(s, A[i/2] + 1);
            else s = A[i-2] + 1;
        }
        
        if(s > 0) A[i] = MIN(s, A[i-1]+1);
        else A[i] = A[i-1] + 1;
    }

    printf("%d", A[N]);
    return 0;
}