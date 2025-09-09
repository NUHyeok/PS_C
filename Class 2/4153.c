#include <stdio.h>
#include <math.h>

int main(void){
    int A, B, C;

    while(1){
        scanf("%d %d %d", &A, &B, &C);
        if (A == 0 && B == 0 && C == 0){
            break;
        }

        else if (A > B && A > C){
            if (pow(A,2) == pow(B,2) + pow(C,2)){
                printf("right\n");
            }
            else{
                printf("wrong\n");
            }
        }

        else if (B > A && B > C){
            if (pow(B,2) == pow(A,2) + pow(C,2)){
                printf("right\n");
            }
            else{
                printf("wrong\n");
            }
        }

        else if (C > B && C > A){
            if (pow(C,2) == pow(B,2) + pow(A,2)){
                printf("right\n");
            }
            else{
                printf("wrong\n");
            }
        }
    }

    return 0;
}