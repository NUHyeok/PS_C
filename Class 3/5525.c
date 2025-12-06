#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N, M, cnt = 0;
    int ans = 0;
    scanf("%d %d", &N, &M);
    char* A = (char *)malloc(M+1);

    scanf("%s", A);
    int i = 0;

    while(i < M-2){
        if(A[i] == 'I' && A[i+1] == 'O' && A[i+2] == 'I'){
            cnt++;
            i += 2;
            if(cnt == N){
                ans++;
                cnt--;
            }
        }
        else{
            cnt = 0;
            i++;
        }
    }

    printf("%d", ans);
    return 0;




}