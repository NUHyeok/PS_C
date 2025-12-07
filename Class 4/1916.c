#include <stdio.h>
#include <string.h>
#define min(x,y) (((x) > (y)) ? (y) : (x))

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    int dp[1001];
    memset(dp, 100000, sizeof(dp));
    dp[1] = 0;

    int start, end, cost;

    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &start, &end, &cost);
        dp[end] = min(dp[end], dp[start] + cost);
    }

    scanf("%d %d", &start, &end);
    printf("%d", dp[end] - dp[start]);
    return 0;


}