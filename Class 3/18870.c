#include <stdio.h>
#include <stdlib.h>

typedef struct Num{
    long long num;
    int index;
}Num;

int compare(const void *a, const void *b){
    Num *na = (Num *)a;
    Num *nb = (Num *)b;

    if (na->num < nb->num) return -1;
    if (na->num > nb->num) return 1;

    return 0;
}

int main(void){
    int N;
    scanf("%d", &N);
    Num *A = (Num *)malloc(N * sizeof(Num));

    for(int i = 0; i < N; i++){
        scanf("%lld", &A[i].num);
        A[i].index = i;
    }
    
    qsort(A, N, sizeof(Num), compare);

    int *results = (int *)malloc(N * sizeof(int));
    int rank = 0;

    results[A[0].index] = 0;
    for(int i = 1; i < N; i++){
        if(A[i].num > A[i-1].num) rank++;
        results[A[i].index] = rank;
    }

    for(int i = 0; i < N; i++){
        printf("%d ", results[i]);
    } 
    free(A);
    free(results);

    return 0;


}