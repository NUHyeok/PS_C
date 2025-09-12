#include <stdio.h>

int main(void){
    int N,sum, k, is = 0;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++){
        sum = 0;
        k = i;
        sum += k;
        while (k >= 10){
            sum += k % 10;
            k = k / 10;

        }
        sum += k;

        if(sum == N) {
            printf("%d", i);
            is = 1;
            break;
        }
    }

    if (is == 0){
        printf("0");
    }

    return 0;
}