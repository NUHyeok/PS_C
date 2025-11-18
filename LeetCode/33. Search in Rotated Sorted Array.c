int FindMin(int* nums, int numsSize){
    int left = 0;
    int right = numsSize - 1;

    while(left < right){
        int mid = left + (right - left) / 2;

        if(nums[mid] > nums[right]){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return left;
}

int search(int* nums, int numsSize, int target) {
    int min_index = FindMin(nums, numsSize);

    int left = min_index;
    int right = numsSize - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    }

    left = 0;
    right = min_index - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    }

    return -1;
}