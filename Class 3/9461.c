#include <stdio.h>

int main(void){
    int N;
    int index = 5;
    scanf("%d", &N);
    long long P[101] = {0};
    P[1] = 1; P[2] = 1; P[3] = 1; P[4] = 2; P[5] = 2;

    for(int i = 0; i < N; i++){
        int K;
        scanf("%d", &K);
        if(P[K] == 0){
            for(int j = index+1; j <= K; j++){
                P[j] = P[j-1] + P[j-5];
                
            }
            index = K;
        }


        printf("%lld\n", P[K]);
        
        
    }
}