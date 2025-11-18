#include <stdio.h>
#include <stdlib.h>

int Square[128][128];
int white;
int blue;

void solve(int r, int c, int size){
    if(size == 0) return;

    int color = Square[r][c];
    int same = 1;

    for(int i = r; i < r+size; i++){
        for(int j = c; j < c+size; j++){
            if(color != Square[i][j]){
                same = 0;
                break;
            }
        }
        if(!same) break;
    }

    if(same){
        if(color == 1) blue++;
        else white++;
    }
    else{
        int new_size = size / 2;
        solve(r,c,new_size);
        solve(r+new_size,c,new_size);
        solve(r, c+new_size, new_size);
        solve(r+new_size, c+new_size, new_size);
    }


}


int main(void){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &Square[i][j]);
        }
    }

    solve(0,0,N);
    printf("%d\n", white);
    printf("%d", blue);

    return 0;


}