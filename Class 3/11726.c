#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    int dp[1001] = {0};
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= N; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    printf("%d", dp[N]);
    return 0;
}