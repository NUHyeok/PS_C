#include <stdio.h>
#include <string.h>

int main(void){
    int N;
    scanf("%d", &N);
    int *node = (int *)malloc((N+1) * sizeof(int));
    memset(node, -1, (N+1) * sizeof(int));

    for(int i = 0; i < N - 1; i++){
        int a,b;
        scanf("%d %d", &a, &b);

        if(a == 1) node[b] = a;
        else if(b == 1) node[a] = b;
        else if(node[b] != -1) node[a] = b;
        else if(node[a] != -1) node[b] = a;

    }

    for(int i = 2; i <= N; i++){
        printf("%d\n", node[i]);
    }
    return 0;

}

