#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    long long A[100001] = {0};

    for(int i = 1; i <= N; i++){
        scanf("%lld", &A[i]);
        A[i] = A[i] + A[i-1];
        
    }

    while(M--){
        int i, j;
        scanf("%d %d", &i, &j);

        printf("%lld\n", A[j] - A[i-1]);

    }

    return 0;

    

    
}