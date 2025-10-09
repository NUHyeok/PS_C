#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N, K, s = 0;;
    scanf("%d %d", &N, &K);

    int *A =(int *)malloc(N * sizeof(int));

    for(int i = N-1; i >= 0; i++){
        scanf("%d", A[i]);
    }
    for(int i = 0; i < N; i++){
        if(K > 0){
            s += K / A[i];
            K = K % A[i];
        }
        else break;
    }

    printf("%d", s);
    return 0;
}