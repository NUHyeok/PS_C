#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N, K;
    scanf("%d %d", &N, &K);

    if (N == 1) {
        printf("<1>");
        return 0;
    }
    
    int *A = (int *)calloc(N, sizeof(int));
    int p = K-1;
    for(int i = 0; i < N; i++){
        int cnt = 0;
        if(i > 0){
            while (cnt < K){
                p++;
                if(p >= N) p = p - N; 
                if(A[p] == 0) cnt++;
            }
        }
        A[p] = 1;

        if(i == 0) printf("<%d, ", p+1);
        else if(i > 0 && i < N-1) printf("%d, ", p+1);
        else printf("%d>", p+1);
    }

    free(A);
    return 0;
}