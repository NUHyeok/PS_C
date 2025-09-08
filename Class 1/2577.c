#include <stdio.h>

int main(void){
    int A, B, C;
    int num[10] = {0};
    int sum;
    int n;

    scanf("%d %d %d", &A, &B, &C);
    sum = A*B*C;

    while (sum > 9){
        n = sum % 10;
        num[n] += 1;
        sum = sum / 10;
    }

    num[sum] += 1;

    for (int i = 0; i < 10; i++){
        printf("%d\n", num[i]);
    }

    return 0;


}