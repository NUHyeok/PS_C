#include <stdio.h>
#define min(x,y) ((x) < (y) ? (x) : (y))

int main(void){
    int N;
    scanf("%d", &N);

    int dp[50001] = {0};
    
    for(int i = 1; i <= N; i++){
        dp[i] = i;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j*j <= i; j++){
            dp[i] = min(dp[i], 1 + dp[i - j*j]);
        }
    }

    printf("%d", dp[N]);
    return 0;
}