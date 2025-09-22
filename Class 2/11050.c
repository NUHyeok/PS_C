#include <stdio.h>

int main(void){
    int N, K;
    scanf("%d %d", &N, &K);
    int sum = 1;

    for(int i = 1; i < K+1; i++){
        sum *= N;
        N--;
    }
    for(int i = 1; i < K+1; i++){
        sum /= i;
    }

    printf("%d", sum);

    return 0;
}