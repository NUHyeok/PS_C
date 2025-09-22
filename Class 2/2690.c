#include <stdio.h>

int main(void){
    int min = 1, i = 2;
    int A, B;
    scanf("%d %d", &A, &B);

    while(i <= A*A || i <= B*B){
        while(A % i == 0 && B % i == 0){
            min *= i;
            A /= i;
            B /= i;
        }
        i++;
    }

    printf("%d\n", min);
    printf("%d", min * A * B);

    return 0;
}