#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N,K;
    scanf("%d %d", &K, &N);
    int *len = (int *)malloc(K * sizeof(int));
    long long max = 0;
    long long low = 1, mid;
    for(int i = 0; i < K; i++){
        scanf("%d", &len[i]);
        if(max < len[i]) max = len[i];
    }
    long long min = 0;
    while(low <= max){
        long long c = 0;
        mid = (low + max) / 2;
        for(int i = 0; i < K; i++){
            c += len[i] / mid;
        }

        if(c < N){
            max = mid - 1;
        }
        if(c >= N){
            low = mid + 1;
            min = mid;
        }

    }


    
    free(len);
    printf("%lld", min);
    return 0;

}