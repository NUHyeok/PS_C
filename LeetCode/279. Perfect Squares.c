#define min(x,y) (((x) > (y)) ? (y) : (x))
int numSquares(int n) {
    int *dp = (int *)malloc((n+1) * sizeof(int));
    int max = 1;
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        if(i == ((max+1) * (max+1))){
            dp[i] = 1;
            max++;
        }
        else{
            dp[i] = 1 + dp[i - max * max];
            for(int j = max-1; j >= 1; j--){
                dp[i] = min(dp[i], 1+ dp[i - j*j]);
            }
        }
    }

    return dp[n];
}