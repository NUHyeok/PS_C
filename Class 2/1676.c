#include <stdio.h>

int main(void){
    int cnt = 0;
    int N;
    scanf("%d", &N);

    for(int i = N; i > 1; i--){
        int a = i;
        while (a % 5 == 0){
            a /= 5;
            cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}