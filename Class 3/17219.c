#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char site[21];
    char password[21];
}ID;

int compare(const void *a, const void *b){
    return strcmp(((ID *)a)-> site, ((ID *)b) -> site);
}

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    ID *p = (ID *)malloc(N * sizeof(ID));

    for(int i = 0; i < N; i++){
        scanf("%20s %20s", p[i].site, p[i].password);
    }
    qsort(p, N, sizeof(ID), compare);

    for(int i = 0; i < M; i++){
        char passw[21];
        scanf("%20s", passw);

        ID key;
        strcpy(key.site, passw);
        ID *result = (ID *)bsearch(&key, p, N, sizeof(ID), compare);
        if(result != NULL){
            printf("%s\n", result -> password);
        }
    }

    free(p);

    return 0;
}