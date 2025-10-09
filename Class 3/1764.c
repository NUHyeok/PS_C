#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_char(const void *a, const void *b){
    return strcmp(*(char **)a, *(char **)b);
}

int main(void){
    int N, M, s = 0;
    scanf("%d %d", &N, &M);

    char **A = (char **)malloc(N * sizeof(char *));
    char **B = (char **)malloc(M * sizeof(char *));

    for (int i = 0; i < N; i++){
        A[i] = (char *)malloc(21 * sizeof(char));
        scanf("%20s", A[i]);
    }

    qsort(A, N, sizeof(char *), compare_char);

    for(int i = 0; i < M; i++){
        char k[21];
        scanf("%20s", k);
        char *p_k = k;
        char *result = (char *)bsearch(&p_k, A, N, sizeof(char *), compare_char);
        if(result != NULL){
            B[s] = malloc(21);
            strcpy(B[s], k);
            s++;
        }
    }
    

    qsort(B, s, sizeof(char *), compare_char);

    printf("%d\n", s);
    for(int i = 0; i < s; i++){
        printf("%s\n", B[i]);
    }

    return 0;

}