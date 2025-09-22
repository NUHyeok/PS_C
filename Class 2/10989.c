#include <stdio.h>

int main(void){
    int N,a, A[10001] = {0};

    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d", &a);
        A[a]++;
    }

    for(int k = 1; k < 10001; k++){
        while(A[k] > 0){
            printf("%d\n", k);
            A[k]--;
        }
    }

    return 0;
}