#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N;
    scanf("%d", &N);

    int *target = (int *)malloc(N * sizeof(int));
    int *A = (int *)malloc(N * sizeof(int));
    char *s = malloc((2*N + 1) * sizeof(char));

    for(int i = 0; i < N; i++){
        scanf("%d", &target[i]);
    }

    int i = 0, k = 2, j = 0, z = 1, is = 1;
    A[0] = 1;
    s[0] = '+';
    while(i < N){
        if(A[j] < target[i]){
            j++;
            A[j] = k++; 
            s[z++] = '+';
        }
        else if (A[j] == target[i]){
            j--;
            i++;
            s[z++] = '-';
        }
        else {
            printf("NO");
            is = 0;
            break;
        }
    }

    if(is){
        for(int a = 0; s[a] == '+' || s[a] == '-'; a++){
            printf("%c\n", s[a]);
        }
    }

    free(target);
    free(A);
    free(s);

    return 0;
}