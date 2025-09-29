#include <stdio.h>

int main(void){
    int a[4];
    int k[2][2] = {0};
    int is = 1;
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);

    for(int i = 0; i < 4; i++){
        int cnt = 1;
        for (int j = 0; j < 4; j++){
            if(a[i] < a[j]) cnt++;
            k[i/2][i%2] = cnt;
        }
    }

    if(k[0][0] == k[1][1] + 1 || k[0][0] == k[1][1] - 1){
        printf("Ribbon");
        is = 0;
    }
    else if(k[1][0] == k[0][1] + 1 || k[1][0] == k[0][1] - 1){
        printf("Ribbon");
        is = 0;
    }

    if(is) printf("Nope");
        
    return 0;
}