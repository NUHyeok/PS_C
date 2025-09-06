#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    if (N % 400 == 0){
        printf("1");
    }

    else if (N % 100 == 0){
        printf("0");
    }

    else if (N % 4 == 0){
        printf("1");
    }

    else{
        printf("0");
    }

    return 0;

}