#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N;
    scanf("%d", &N);
    int *A = (int *)malloc(N * sizeof(int));
    int *dp = (int *)malloc(N * sizeof(int));

    int max_val = 1;
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
        dp[i] = 1;
    }

    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(A[i] > A[j]){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(max_val < dp[i]) max_val = dp[i];
    }
    printf("%d", max_val);
    return 0;
}