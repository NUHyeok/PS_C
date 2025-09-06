#include <stdio.h>

int main(void){
    int max = 0, max_index, num[9];
    for (int i = 0; i < 9; i++){
        scanf("%d", &num[i]);
        if (max < num[i]){
            max = num[i];
            max_index = i+1;
        }

    }
    printf("%d\n%d", max, max_index);
    return 0;

}