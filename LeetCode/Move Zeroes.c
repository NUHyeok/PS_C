void moveZeroes(int* nums, int numsSize) {
    int cnt = 0, j = 0;

    for (int i = 0; i < numsSize; i++){
        
        if (nums[i] != 0){
            nums[j] = nums[i];
            j++;
        }
    }

    for (int k = j; k < numsSize; k++){
        nums[j] = 0;
        j++;
    }

}