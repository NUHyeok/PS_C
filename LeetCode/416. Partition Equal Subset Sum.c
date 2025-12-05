bool canPartition(int* nums, int numsSize) {
    int sum = 0;
    for(int i = 0; i < numsSize; i++) sum += nums[i];

    if(sum % 2 == 1) return false;

    int target = sum / 2;
    int *dp = (int *)malloc((target+1) * sizeof(int));
    memset(dp, 0, (target+1)*sizeof(int));
    dp[0] = 1;

    for(int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if(num > target) return false;

        for(int s = target; s >= num; s--) {
            if(dp[s - num])
                dp[s] = 1;
        }

        if(dp[target]) return true;
    }
    return dp[target];
}