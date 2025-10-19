int trailingZeroes(int n) {
    int cnt = 0;

    for(int i = 5; i <= n; i = i+5) {
        int j = i;
        while(j % 5 == 0){
            j /= 5;
            cnt++;
        }
    }

    return cnt;
}