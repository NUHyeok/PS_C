#include <stdio.h>

long long try = 0;
int N, r, c;

void recursion(int a, int row, int col){
    long long s = 1;

    if(a == 0) {
        return;
    }

    for(int i = 0; i < a - 1; i++) s *= 2;

    

    if(row < s && col < s){
        recursion(a - 1, row, col);
    }
    else if(row < s && col >= s){
        try += s*s;
        recursion(a-1, row, col-s);
    }
    else if(row >= s && col < s){
        try += 2*s*s;
        recursion(a-1, row-s, col);
    }
    else if (row >= s && col >= s){
        try += 3*s*s;
        recursion(a-1, row-s, col-s);
    }

    
}
int main(void){
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);

    recursion(N, r, c);
    printf("%lld", try);
    return 0;
}