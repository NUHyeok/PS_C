#include <stdio.h>

int A[20000001];

int main(void){
    int N, M;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        int a;
        scanf("%d", &a);
        A[a+10000000]++;
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++){
        int a;
        scanf("%d", &a);
        printf("%d ", A[a+10000000]);
    }

    return 0;
}