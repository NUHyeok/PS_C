int removeDuplicates(int* nums, int numsSize) {
    int cnt = 1;
    for (int j = 1; j < numsSize; j++){
        if(nums[cnt-1] != nums[j]){
            nums[cnt] = nums[j];
            cnt++;
        }
    }
    return cnt;
    
}