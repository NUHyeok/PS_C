#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    int min = N;

    for(int i = 0; i <= N / 5; i++){
        int w = N;
        int s = i;
        w -= 5*i;
        if(w % 3 == 0){
            s += w / 3;
            if(min > s) min = s;
        }
    }

    if(min != N){
        printf("%d", min);
    }
    else{
        printf("-1");
    }

    return 0;

}