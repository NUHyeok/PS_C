#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    int N,cnt = 0,f;
    scanf("%d", &N);
    int *A = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++){
        f = 1;
        scanf("%d", &A[i]);
        if (A[i] > 1){
            for (int j = 2; j *j <= A[i]; j++){
                if (A[i] % j == 0){
                    f = 0;
                    break;
                    
                }
            }

            if (f == 1){
                cnt++;
            }

        }
    }

    free(A);
    printf("%d", cnt);
    return 0;


}