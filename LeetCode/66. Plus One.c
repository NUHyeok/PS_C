/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *A = (int *)malloc((digitsSize + 1) * sizeof(int));
    int s = 1;
    int sum = 0;
    int a = 1;

    for(int i = 0; i < digitsSize; i++){
        if(digits[i] != 9){
            a = 0; 
            break;
        }
    }

    if(a){
        for(int i = digitsSize - 1; i >= 0; i--){
            sum = digits[i] + s;

            if(sum == 10){
                A[i+1] = 0;
            }
            else{
                A[i+1] = sum;
                s = 0;
            }
        }
        if(s == 1) A[0] = 1;
        *returnSize = digitsSize + 1;
    }
    else{
        for(int i = digitsSize - 1; i >= 0; i--){
            sum = digits[i] + s;

            if(sum == 10){
                A[i] = 0;
            }
            else{
                A[i] = sum;
                s = 0;
            }
        }
        *returnSize = digitsSize;
    }

    return A;
}