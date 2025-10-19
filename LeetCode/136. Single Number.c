int singleNumber(int* nums, int numsSize) {
    int cnt = 0;

    for(int i = 0; i < numsSize; i++){
        cnt ^= nums[i];
    }
    return cnt;
}