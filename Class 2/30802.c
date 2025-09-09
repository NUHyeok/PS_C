#include <stdio.h>

int main(void){
    int N, T ,P, sum_T = 0, sum_P, d;
    int Size[6];

    scanf("%d", &N);

    for (int i = 0; i < 6; i++){
        scanf("%d", &Size[i]);
    }

    scanf("%d %d", &T, &P);

    for (int j = 0; j < 6; j ++){
        sum_T += Size[j] / T;
        if (Size[j] % T != 0){
            sum_T += 1;
        }
    }

    sum_P = N / P;
    d = N % P;

    printf("%d\n%d %d", sum_T, sum_P, d);
    return 0;

}