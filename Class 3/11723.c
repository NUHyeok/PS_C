#include <stdio.h>
#include <string.h>

int p[21];

void add(int i, int *p);
void remove_int(int i, int *p);
void check(int i, int *p);
void toggle(int i, int *p);
void all(int *p);
void empty(int *p);


int main(void){
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        int a;
        char s[7];

        scanf("%s", s);
        if(!strcmp("add", s)){
            scanf("%d", &a);
            add(a, p);
        }
        else if(!strcmp("remove", s)){
            scanf("%d", &a);
            remove_int(a, p);
        }
        else if(!strcmp("check",s)){
            scanf("%d", &a);
            check(a, p);
        }
        else if(!strcmp("toggle", s)){
            scanf("%d", &a);
            toggle(a,p);
        }
        else if(!strcmp("all", s)){
            all(p);
        }
        else if(!strcmp("empty", s)){
            empty(p);
        }

        
    }
}

void add(int i, int *p){
    p[i] = 1;
}

void remove_int(int i, int *p){
    p[i] = 0;
}

void check(int i, int *p){
    if(p[i] == 1) printf("1\n");
    else printf("0\n");
}

void toggle(int i, int *p){
    if(p[i] == 0) p[i] = 1;
    else p[i] = 0;
}

void all(int *p){
    for(int i = 1; i < 21; i++) p[i] = 1;
}

void empty(int *p){
    for(int i = 1; i < 21; i++) p[i] = 0;    
}







