#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[21];
}Pokemon;

int compare(const void *a, const void *b){
    return strcmp(((Pokemon *)a) -> name , ((Pokemon *)b) -> name);
}

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    Pokemon *p = (Pokemon *)malloc(N * sizeof(Pokemon));
    char **index = (char **)malloc(N * sizeof(char *));

    for(int i = 0; i < N; i++){
        p[i].id = i+1;
        scanf("%20s", p[i].name);
        index[i] = malloc(21);
        strcpy(index[i], p[i].name);
    }

    qsort(p, N, sizeof(Pokemon), compare);

    for (int i = 0; i < M; i++){
        char s[21];
        scanf("%20s", s);

        if(s[0] >= '1' && s[0] <= '9'){
            printf("%s\n", index[atoi(s) - 1]);
        }
        else{
            Pokemon key;
            strcpy(key.name, s);
            
            Pokemon *result = (Pokemon *)bsearch(&key, p, N, sizeof(Pokemon), compare);
            if (result != NULL) {
                printf("%d\n", result->id);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        free(index[i]);
    }
    free(index);
    free(p);

    return 0;
}