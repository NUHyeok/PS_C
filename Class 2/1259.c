#include <stdio.h>
#include <stdlib.h>

int main(void){
    while(1){
        int A, i = 0, is = 1;
        int S[6];
        scanf(" %d", &A);
        if(A == 0) break;
    
        while(A > 0){
            S[i] = A % 10;
            A = A / 10;
            i++;
        }

        for(int j = 0; j < (i / 2); j++){
            if(S[j] != S[i-j-1]){
                printf("no\n");
                is = 0;
                break;
            }
        }

        if(is){
            printf("yes\n");
        }
        
    }

    return 0;
}