#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct person{
    int age;
    char name[101];
    int index;
};

int compare(const void *a, const void *b){
    const struct person *p = (const struct person *)a;
    const struct person *q = (const struct person *)b;

    if(p->age != q->age) return p->age - q->age;
    return p->index - q->index;
}

int main(void){
    int N;
    scanf("%d", &N);

    struct person *p = (struct person *)malloc(N * sizeof(struct person));

    for(int i = 0; i < N; i++){
        scanf("%d %s", &p[i].age, p[i].name);
        p[i].index = i;
    }

    qsort(p, N, sizeof(struct person), compare);

    for(int i = 0; i < N; i++){
        printf("%d %s\n", p[i].age, p[i].name);
    }

    return 0;
}