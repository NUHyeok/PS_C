#include <stdio.h>

int main(void){
    int num[8];

    for (int i = 0; i < 8; i++){
        scanf("%d", &num[i]);
    }

    if (num[0] > num[1]){
        for (int j = 1; j < 8; j++){
            if(num[j-1] < num[j]){
                printf("mixed");
                return 0;
            }
            
        }
        printf("descending");
    }

    if (num[0] < num[1]){
        for (int k = 1; k < 8; k++){
            if(num[k-1] > num[k]){
                printf("mixed");
                return 0;
            }
        }
        printf("ascending");
    }
    return 0;
}