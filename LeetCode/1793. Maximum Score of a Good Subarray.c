int maximumScore(int* nums, int numsSize, int k) {
    int left = k;
    int right = k;
    int min = nums[k];
    int max = min;

    while(left > 0  || right < numsSize - 1){
        if(left == 0) right++;
        else if(right == numsSize - 1) left--;
        else if(nums[left-1] < nums[right+1]) right++;
        else left--;

        if (nums[left] < min)
            min = nums[left];
        
        if(nums[right] < min) min = nums[right];

        int score = min * (right - left + 1);
        if (score > max)
            max = score;
    }

    return max;
}