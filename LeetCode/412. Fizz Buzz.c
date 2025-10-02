/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char **A = malloc(n * sizeof(char *));
    for (int i = 1; i <= n; i++){
        if(i % 3 == 0 && i % 5 ==0){
            A[i-1] = malloc(9 * sizeof(char));
            strcpy(A[i-1], "FizzBuzz");
        }
        else if(i % 3 == 0){
            A[i-1] = malloc(5 * sizeof(char));
            strcpy(A[i-1], "Fizz");
        }
        else if(i % 5 ==0){
            A[i-1] = malloc(5 * sizeof(char));
            strcpy(A[i-1], "Buzz");
        }
        else{
            A[i-1] = malloc(6 * sizeof(char));
            sprintf(A[i-1], "%d", i);
        }
    }

    return A;
}