int countPrimes(int n) {
    int A[5000001] = {0};
    int cnt = 0;
    A[0] = 1;
    A[1] = 1;

    for(int i = 2; i < n; i++){
        if(!A[i]){
            for(int j = i + i; j < n; j = j + i){
                A[j] = 1;
            }
            cnt++;
        }
    }

    return cnt;
}