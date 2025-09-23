#include <stdio.h>
#include <stdlib.h>


int main(void){
    int N;
    scanf("%d", &N);

    int **A = (int *)malloc(N* sizeof(int *));
    for (int i = 0; i < N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        A[i] = (int*)malloc(2 * sizeof(int));
        A[i][0] = a;
        A[i][1] = b;
    }

    for(int i = 0; i < N; i++){
        int k = 1;
        for (int j = 0; j < N; j++){
            if(A[i][0] < A[j][0] && A[i][1] < A[j][1]) k++;
        }
        printf("%d ", k);
    }



    return 0;
}