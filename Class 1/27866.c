#include <stdio.h>

int main(void){
    char S[1000];
    scanf("%1000s", S);
    int i;
    scanf("%d", &i);

    printf("%c", S[i-1]);
    return 0;


}