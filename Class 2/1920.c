#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if(x > y) return 1;
    else if(x < y) return -1;
    return 0;
}

int main(void){
    int N, M;
    scanf("%d", &N);
    long long *A = (long long *)malloc(N * sizeof(long long));

    for(int i = 0; i < N; i++){
        scanf("%lld", &A[i]);
    }

    qsort(A, N, sizeof(long long), compare);

    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        long long s;
        scanf("%lld", &s);
        int left = 0, right = N-1, mid, is = 1;
        while (left <= right){
            mid = (left + right) / 2;
            if(A[mid] < s) left = mid + 1;
            else if(A[mid] > s) right = mid - 1;
            else{
                printf("1\n");
                is = 0;
                break;
            }
        }
        
        if(is) printf("0\n");
    }
    free(A);

    return 0;
}