// brute_force
/*
int maxSubArray(int* nums, int numsSize) {
    int max_sum = nums[0];
    int best = nums[0];
    int now;

    for(int i = 1; i < numsSize; i++){
        now = max_sum + nums[i];
        if (nums[i] > now){
            max_sum = nums[i];
            if (max_sum > best) best = max_sum;
        }
        else{
            max_sum = now;
            if (max_sum > best) best = max_sum;
        }

    }
    return best;    
    
    

}*/

// 분할 정복

