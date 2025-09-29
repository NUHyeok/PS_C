int firstMissingPositive(int* nums, int numsSize) {
    int a[100002] = {0};

    for(int i = 0; i < numsSize; i++){
        if(nums[i] > 0 && nums[i] <= 100000){
            a[nums[i]] = 1;
        }
    }

    for(int i = 1; i < numsSize+2; i++){
        if(a[i] == 0){
            return i;
        }
    }
    return 0;
}