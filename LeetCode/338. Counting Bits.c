/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int *ans = (int *)malloc((n+1) * sizeof(int));
    int k = 0;
    int a = 1;
    ans[0] = 0;
    for(int i = 1; i <= n; i++){
        if(i == a){
            k = a;
            a = 2 * a;
        }
        ans[i] = 1 + ans[i - k];
    }
    *returnSize = n + 1;
    return ans;
}
