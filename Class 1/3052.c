#include <stdio.h>

int main(void){
    int num[10];
    int n[10] = {0};
    int cnt = 0;

    for(int i = 0; i < 10; i++){
        int status = 1;
        scanf("%d", &num[i]);
        n[i] = num[i] % 42;

        for (int j = 0; j < i; j++){
            if (n[i] == n[j]){
                status = 0;
                break;
                }
            }

        if (status == 1){
            cnt++;
        }
                
        
    }
    printf("%d", cnt);
    return 0;
}