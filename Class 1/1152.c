#include <stdio.h>

int main(void){
    char C[1000001];
    int cnt = 0;
    int inWord = 0;

    fgets(C, sizeof(C), stdin);
    for (int i = 0; C[i] != '\0'; i++){
        if (C[i] == '\n') break;
        if (C[i] != ' '){
            if (!inWord){
                cnt++;
                inWord = 1;
            }

        }
        else{
            inWord = 0;
        }
    }


    printf("%d", cnt);
    return 0;
}