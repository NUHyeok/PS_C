#include <stdio.h>

int main(void){
    int N;
    long long sum = 0;
    char A;
    long long a = 1;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf(" %c", &A);
        sum = (sum + (long long)(A - 'a' + 1) * a) % 1234567891;
        a = (a * 31) % 1234567891;
    }

    printf("%lld", sum);
    return 0;
}