#define min(x,y) ((x) > (y)) ? (y) : (x)
int nthUglyNumber(int n) {
    int dp[1691] = {0};
    dp[1]= 1;

    int p2 = 1, p3 = 1, p5 = 1;
    int cnt = 2;

    while(cnt <= n){
        int next2 = dp[p2] * 2;
        int next3 = dp[p3] * 3;
        int next5 = dp[p5] * 5;

        int min_value = min(min(next2, next3), next5);

        if(min_value == next2) p2++;
        if(min_value == next3) p3++;
        if(min_value == next5) p5++;

        dp[cnt++] = min_value;
    }
    return dp[n];
}