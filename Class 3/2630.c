#include <stdio.h>
#include <stdlib.h>

int A[128][128];
int white_count = 0;
int blue_count = 0;

void solve(int r, int c, int size) {
    int color = A[r][c];     int same = 1;        

    for (int i = r; i < r + size; i++) {
        for (int j = c; j < j + size; j++) {
            if (color != A[i][j]) {
                same = 0; 
                break;
            }
        }
        if (!same) { 
            break;
        }
    }

    if (same) {
        if (color == 1) {
            blue_count++;
        } else {
            white_count++;
        }
        return; 
    } else {
        int new_size = size / 2;
        
        solve(r, c, new_size);                      
        solve(r, c + new_size, new_size);          
        solve(r + new_size, c, new_size);           
        solve(r + new_size, c + new_size, new_size);
        return; 
    }
}

int main(void) {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    solve(0, 0, N);
    printf("%d\n", white_count);
    printf("%d\n", blue_count);

    return 0;
}