#include <stdio.h>
#include <string.h>

int main(void){
    char s[105];

    while(fgets(s, sizeof(s), stdin)){
        
        int is = 1;

        int i = 0;
        char q[105];

        if(s[0] == ".") break;

        for(int j = 0; s[j] != '\0'; j++){
            if(s[j] == '(' || s[j] == '['){
                q[i++] = s[j];
            }
            else if(s[j] == ')'){
                if(i == 0 || q[i-1] != '('  ){
                    is = 0;
                    break;
                }
                else{
                    i--;
                }
            }
            else if(s[j] == ']'){
                if(i == 0 || q[i-1] != '['){
                    is = 0;
                    break;
                }
                else{
                    i--;
                }
            }

        }

        if(i == 0 && is == 1) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}