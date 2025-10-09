#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        int index = 0, is = 1;
        char c[51];
        scanf("%s", c);

        char stack[26];

        for(int j = 0; c[j] != '\0'; j++){
            if (c[j] == '('){
                stack[index] = c[j];
                index ++;
            }
            else if (c[j] == ')'){
                if(stack[index - 1] == '('){
                    index--;
                }
                else{
                    is = 0;
                    break;
                }
            }
        }

        if(index == 0 && is){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}