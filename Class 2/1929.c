#include <stdio.h>
#include <stdlib.h>

int main(void){
    int M, N;
    scanf("%d %d", &M, &N);
    int *A = (int *)calloc(N+1, sizeof(int));
    A[0] = 1;
    A[1] = 1; 
    
    for(int i = 2; i * i <= N; i++){
        if(!A[i]){
            for(int j = i * i; j <= N; j += i){
                A[j] = 1;
            }
        }
    }

    for(int i = M; i <= N; i++){
        if(!A[i]){
            if(i > 1) printf("%d\n", i);
        }
    }

    free(A);

    return 0;


}