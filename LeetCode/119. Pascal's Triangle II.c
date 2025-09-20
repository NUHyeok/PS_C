/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int *A = (int *)malloc((rowIndex + 1) * sizeof(int));
    int **B = malloc((rowIndex + 1) * sizeof(int *));
    *returnSize = rowIndex + 1;

    for (int i = 0; i < rowIndex; i++){
        B[i] = malloc((i+1) * sizeof(int));

        for (int j = 0; j <= i; j++){
            if (j == 0 || j == i){
                B[i][j] = 1;
            }
            else{
                B[i][j] = B[i-1][j] + B[i-1][j-1];
            }
        }
    
    for (int i = 0; i <= rowIndex; i++){
        if(i == 0 || i == rowIndex){
            A[i] = 1;
        }
        else{
            A[i] = B[rowIndex - 1][i] + B[rowIndex - 1][i-1];
        }
    }

    return A;

    

}