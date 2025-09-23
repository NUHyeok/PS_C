#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    int cnt = 0, ans = 666;
    
    while(cnt < N){
        int a = ans;
        int cn = 0;
        while (a > 0){
            if(a % 10 == 6){
                cn++;
            }
            else{
                cn = 0;
            }

            if(cn == 3){
                cnt++;
                break;
            }
            a /= 10;
        }
        ans++;
        
    }

    printf("%d", ans-1);
    return 0;

        
}