bool splitArraySameAverage(int* nums, int numsSize) {
    int totalSum = 0;
    for(int i = 0; i < numsSize; i++) totalSum += nums[i];
    
    int m = numsSize / 2;
    bool possible = false;

    for (int k = 1; k <= m; k++) {
        if ((long long)totalSum * k % numsSize == 0) {
            possible = true;
            break;
        }
    }
    if (!possible) return false;

    int* dp = (int*)calloc(totalSum + 1, sizeof(int));
    dp[0] = 1; 

    int currentSum = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        
        // 중복 사용 방지를 위해 합이 큰 쪽에서 작은 쪽으로 순회
        // currentSum까지만 돌면 되므로 최적화 가능
        for (int s = currentSum; s >= 0; s--) {
            if (dp[s] != 0) {
                // dp[s]에 있는 길이들에 각각 1을 더해서(왼쪽 시프트 1)
                // dp[s + x]에 기록(OR 연산)
                dp[s + x] |= (dp[s] << 1);
            }
        }
        currentSum += x;
    }

    bool result = false;
    
    for (int k = 1; k <= m; k++) {
        // 평균이 같아지는 조건: TotalSum * k == SubSum * N
        // 즉, SubSum = (TotalSum * k) / N
        if ((long long)totalSum * k % numsSize == 0) {
            int targetSum = totalSum * k / numsSize;
            
            // dp[targetSum]의 k번째 비트가 1인지 확인
            if (dp[targetSum] & (1 << k)) {
                result = true;
                break;
            }
        }
    }

    free(dp);
    return result;
}