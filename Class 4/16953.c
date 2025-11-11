#include <stdio.h>

int main(void){
    int N, M, cnt = 1;
    scanf("%d %d", &N, &M);

    while(N < M){
        if(M % 2 == 1 && M % 10 == 1){
            M = (M-1) / 10;
            cnt++;
        }
        else if(M % 2 == 0){
            M /= 2;
            cnt++;
        }
        else{
            break;
        }
    }

    if(N == M) printf("%d", cnt);
    else printf("-1");
    return 0;

}