#include <stdio.h>
#include <string.h>

int main(void){
    char s[105];

    while (fgets(s, sizeof s, stdin)) {    
        if (s[0] == '.') break;             

        char st[105];
        int top = -1;
        int ok = 1;

        for (int i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
            char c = s[i];
            if (c == '(' || c == '[') {
                st[++top] = c;              
            } else if (c == ')') {
                if (top < 0 || st[top] != '(') { ok = 0; break; }
                top--;                      
            } else if (c == ']') {
                if (top < 0 || st[top] != '[') { ok = 0; break; }
                top--;
            }
        }

        puts((ok && top == -1) ? "yes" : "no");
    }
    return 0;
}
