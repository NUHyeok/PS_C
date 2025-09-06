#include <stdio.h>

int main(void){
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    printf("%d\n", A + B - C);

    int tmp = B;
    int mul = 1;
    while (tmp > 0) {
        mul *= 10;
        tmp /= 10;
    }
    int concat = A * mul + B;

    printf("%d\n", concat - C);

    return 0;
}
