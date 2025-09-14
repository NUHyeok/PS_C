int searchInsert(int* nums, int numsSize, int target) {
    int right = numsSize - 1;
    int left = 0;

    while (left <= right){
        int mid = (right + left) / 2;

        if (nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}