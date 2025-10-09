#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N;
    int index = 0, sum  = 0;
    scanf("%d", &N);
    int *stack = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++){
        int s;
        scanf("%d", &s);
        if (s != 0){
            sum += s;
            stack[index++] = s;
        }
        else if (s == 0){
            if(index == 0) continue;
            else{
                sum -= stack[--index];
            }
        }
    }
    free(stack);
    printf("%d", sum);
    return 0;
}