#include <stdio.h>
#include <math.h>

int main(void){
    int A[5], sum = 0;

    for (int j = 0; j < 5; j ++){
        scanf("%d", &A[j]);
        sum += pow(A[j], 2);
    }
    
    printf("%d", sum % 10);

    return 0;

}