#include <stdio.h>

int main(void){
    int hour, min;
    scanf("%d %d", &hour, &min);

    if (min < 45){
        if (hour == 0){
            hour = 23;
        }
        else{
            hour -= 1;
        }
        min = 60 + min - 45;

    }

    else{
        min -= 45;
    }
    printf("%d %d", hour, min);
    return 0;
}