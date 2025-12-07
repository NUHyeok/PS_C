#include <stdio.h>
#include <string.h>
#define min(x,y) (((x) > (y)) ? (y) : (x))

int main(void){
    int N;
    int A[3] = {0};
    int dp[1000][3];
    memset(dp, 0, sizeof(dp));

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d %d %d", &A[0], &A[1], &A[2]);
        if(i == 0) {
            dp[i][0] = A[0];
            dp[i][1] = A[1];
            dp[i][2] = A[2];
        }
        else{
            dp[i][0] = A[0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = A[1] + min(dp[i-1][2], dp[i-1][0]);
            dp[i][2] = A[2] + min(dp[i-1][0], dp[i-1][1]);
        }

    }

    int min_value = min(min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]);
    printf("%d", min_value);
    return 0;
}