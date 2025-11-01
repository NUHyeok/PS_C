#include <stdio.h>

int main(void){
    char s[51];
    scanf("%s", s);

    int sum = 0;
    int num = 0;
    int is_minus = 0;

    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '-') {
            is_minus = 1;
            sum += num;
            num = 0;
        }
        else if(s[i] == '+'){
            sum += num;
            num = 0;
        }
        else{
            if(is_minus){
                num = num * 10 - (s[i] - '0');
            }
            if(!is_minus){
                num = num * 10 + (s[i] - '0');
            }
        }
    
    }

    printf("%d", sum+num);
    return 0;
    


}