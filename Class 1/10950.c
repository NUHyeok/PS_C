#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);

        printf("%d\n", a+b);
    }

    return 0;
}