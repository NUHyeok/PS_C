#include <stdio.h>
// i Â¦¼ö -> 1, È¦¼ö -> 3

int main(void){
    int s = 0, is = 0; // 0ÀÌ Â¦¼ö, 1Àº È¦¼ö
    char A;
    int ans = 0;

    for(int i = 0; i < 13; i++){
        scanf("%c", &A);
        if(i % 2 == 0){
            if (A == '*'){
                is = 0;
                continue;
            }
            else{
                s += (int)(A - '1') + 1;
            }
        }

        else{
            if(A == '*'){
                is = 1;
                continue;
            }
            else{
                s += ((int)(A - '1') + 1) * 3;
            }
        }
    }

    if (is){
        for (int i = 1; i < 10; i++){
            if((3*i) % 10 == 10 - s % 10){
                ans = i;
                break;
            }
        }
    }
    else{
        ans = 10 - s % 10;;
    }
    printf("%d", ans);
    return 0;
}