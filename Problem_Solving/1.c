#include <stdio.h>

int main(void){
    int N, M, s = 1, a;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++){
        scanf("%d", &a);
        s *= a;
    }

    printf("%d", s % M);
    return 0;

    
}


