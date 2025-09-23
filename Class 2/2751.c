#include <stdio.h>

int main(void){
    int N;
    int S[2000001] = {0};
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        int a;
        scanf("%d", &a);
        S[a + 1000000] = 1;
    }

    for (int i = 0; i < 2000001; i++){
        if(S[i] == 1) printf("%d\n", i - 1000000);
    }

    return 0;
}