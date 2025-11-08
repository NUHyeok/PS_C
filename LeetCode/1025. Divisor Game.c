// 0 -> false, 1 -> true
bool divisorGame(int n) {
    int dp[1001];
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i <= n; i++){
        int k = 2;
        int is = 0;
        while(k*k < i){
            if(k % i == 0){
                if(dp[k / i] == 0){
                    dp[i] = 1;
                    is = 1;
                    break;
                }
            }
            k++;
        }

        if(!is){
            if(dp[i-1] == 0) dp[i] = 1;
            else dp[i] = 0;
        }
    }
    return dp[n];
}