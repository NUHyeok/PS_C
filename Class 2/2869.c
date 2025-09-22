#include <stdio.h>

int main(void){
    int A, B, V, day = 1;
    scanf("%d %d %d", &A, &B, &V);
    
    V -= A;
    if(V % (A - B) == 0) day += V / (A-B);
    else day += (V / (A-B)) + 1;

    printf("%d", day);
    return 0;

}

