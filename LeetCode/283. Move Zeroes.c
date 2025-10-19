void moveZeroes(int* nums, int numsSize) {
    int idx = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i]) nums[idx++] = nums[i];
    }

    for(int i = idx; i < numsSize; i++){
        nums[i] = 0;
    }
}