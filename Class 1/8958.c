#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++){
        char S[80];
        int point = 0;
        int sum = 0;
        scanf("%s", S);

        for (int j = 0; S[j] != '\0'; j++){
            if (S[j] == 'X'){
                point = 0;
            }
            else{
                point += 1;
                sum += point;
            }
        }

        printf("%d\n", sum);
        
    }
    return 0;
}