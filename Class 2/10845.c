#include <stdio.h>
#include <string.h>

int queue[10000];

int main(void){
    int N, front = 0, back = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        char s[6];
        scanf("%s", s);

        if(!strcmp(s, "push")){
            int a;
            scanf("%d", &a);
            queue[back++] = a;
        }
        else if(!strcmp(s, "pop")){
            if (front == back) printf("-1\n");
            else printf("%d\n", queue[front++]);
        }
        else if(!strcmp(s, "size")){
            printf("%d\n", back - front);
        }
        else if(!strcmp(s, "empty")){
            if(front == back) printf("1\n");
            else printf("0\n");
        }
        else if(!strcmp(s, "front")){
            if(front == back) printf("-1\n");
            else printf("%d\n", queue[front]);
        }
        else if(!strcmp(s, "back")){
            if(front == back) printf("-1\n");
            else printf("%d\n", queue[back -1]);
        }
        
    }

    return 0;
}