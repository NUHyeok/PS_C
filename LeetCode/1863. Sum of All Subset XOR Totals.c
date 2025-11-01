int dfs(int index, int currentXOR, int* nums, int numsSize){
    if(index == numsSize){
        return currentXOR;
    }

    int sum_in = dfs(index+1, currentXOR ^ nums[index], nums, numsSize);
    int sum_out = dfs(index+1, currentXOR, nums, numsSize);

    return sum_in + sum_out;

}
int subsetXORSum(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int sum = dfs(0, 0, nums, numsSize);
    return sum;
}