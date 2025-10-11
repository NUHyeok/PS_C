#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N, K, s = 0;
    scanf("%d %d", &N, &K);
    int coin[10] = {0};

    for(int i = 0; i < N; i++){
        scanf("%d", &coin[i]);
    }

    for(int i = N - 1; i >= 0; i--){
        s += K / coin[i];
        K = K % coin[i];
        if(K == 0)break;
    }

    printf("%d", s);
    return 0;




}