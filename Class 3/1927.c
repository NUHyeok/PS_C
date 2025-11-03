#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long X[100000];

int compare(const long long *a, const long long *b){
    return (*b - *a);
}

int main(void){
    int N,num, index = 0;
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        if(num > 0){
            X[index++] = num;
            qsort(X, index, sizeof(long long), compare);
        }
        else if(num == 0){
            if(index == 0) printf("0\n");
            else printf("%lld\n", X[--index]);
            
        }
    }

    return 0;
}