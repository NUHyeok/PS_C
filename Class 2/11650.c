#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}xy;

int compare(const void *a, const void*b){
    const xy *p = (xy *)a;
    const xy *q = (xy *)b;

    if(p->x == q->x) return p->y - q->y;
    return p->x - q->x;
}

int main(void){
    int N;
    scanf("%d", &N);

    xy *p = (xy *)malloc(N * sizeof(xy));

    for(int i = 0; i < N; i++){
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    qsort(p, N, sizeof(xy), compare);

    for(int i = 0; i < N; i++){
        printf("%d %d\n", p[i].x, p[i].y);
    }

    return 0;
}