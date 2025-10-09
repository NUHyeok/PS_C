#include <stdio.h>
#include <string.h>

int stack[10000];

int main(void){
    int N, index = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        char s[6]; 
        int a;
        scanf("%s", s);
        if(!strcmp(s, "push")){
            scanf("%d", &a);
            stack[index++] = a;
        }
        else if (!strcmp(s, "pop")){
            if(index == 0) printf("-1\n");
            else {
                printf("%d\n", stack[--index]);
            }
        }
        else if(!strcmp(s, "size")){
            printf("%d\n", index);
        }
        else if(!strcmp(s, "empty")){
            if(index == 0) printf("1\n");
            else printf("0\n");
        }
        else if(!strcmp(s, "top")){
            if(index == 0) printf("-1\n");
            else printf("%d\n", stack[index - 1]);
        }

    }

    return 0;
}
