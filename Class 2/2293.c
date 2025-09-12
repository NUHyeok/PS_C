#include <stdio.h>

int main(void){
    int N, cnt = 1, i = 1;
    scanf("%d", &N);

    N -= 1;

    while (1){

        if (N > 0){
            N -= 6 * i;
            i++;
            cnt++;
        }

        else{
            break;
        }
    }

    printf("%d", cnt);
    return 0;

}


