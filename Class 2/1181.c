#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareString(const void *a, const void *b){
    char *s1 = *(char **)a;
    char *s2 = *(char **)b;

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    if(len1 != len2){
        return (len1 - len2);
    }

    return strcmp(s1, s2);    
}

int main(void){
    int N;
    scanf("%d", &N);
    char **A = malloc(N * sizeof(char *));

    for (int i = 0; i < N; i++){
        A[i] = malloc(51 * sizeof(char));
        scanf("%s", A[i]);
    }

    qsort(A, N, sizeof(const char*), compareString);

    for(int i = 0; i < N; i++){
        if(i < N-1){
            if(strcmp(A[i],A[i+1]) == 0) continue;
            else printf("%s\n", A[i]);
        }
        else printf("%s\n", A[i]);
    }

    return 0;



    
}