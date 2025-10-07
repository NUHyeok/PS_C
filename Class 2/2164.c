#include <stdio.h>
int main(void){
    int N; scanf("%d",&N);
    int L = 1; while ((L<<1) <= N) L <<= 1;
    int ans = (N == L) ? N : 2*(N - L);
    printf("%d\n", ans);
    return 0;
}
