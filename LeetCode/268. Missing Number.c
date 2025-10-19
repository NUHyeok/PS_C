int missingNumber(int* nums, int numsSize) {
    int min = 0;
    int A[10001] = {0};

    for(int i = 0; i < numsSize; i++){
        A[nums[i]]++;
    }
    for(int i = 0; i < numsSize+1; i++){
        if(A[i] == 0) {
            min = i;
            break;
        }
    }
    return min;
}