long long sum[100001];

int waysToSplit(int* nums, int numsSize) {
    int n = numsSize;
    long long MOD = 1e9 + 7;

    for(int i = 0; i < numsSize; i++){
        sum[i+1] = sum[i] + nums[i];
    }

    long long ans = 0;

    int j_min = 0;
    int j_max = 0;

    for(int i = 0 ; i < numsSize - 2; i++){
        long long S1 = sum[i+1];

        j_min = (j_min > i+1) ? j_min : i+1;
        j_max = (j_max > i+1) ? j_max : i+1;

        while(j_min < numsSize - 1 && sum[j_min + 1] - S1 < S1) j_min++;
        while(j_max < numsSize - 1 && 2 * sum[j_max+1] <= S1 + sum[numsSize]) j_max++;
        if (j_max > j_min) {
            ans = (ans + (j_max - j_min)) % MOD;
        }
    }
    return (int)ans;
}

// S1 <= S2인 지점 / S2 <= S3인 지점 찾기 !! 