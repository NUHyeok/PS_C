#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[25][25];
int checked[25][25];
int cnt[25 * 25];
int index_cnt;
int N;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int compare(const void* a, const void *b){
    return *(int *)a - *(int *)b;
}
 
int dfs(int row, int col){
    int count = 1;
    checked[row][col] = 1;

    for(int i = 0; i < 4; i++) {
        int next_row = row + dy[i];
        int next_col = col + dx[i];

        if(next_row >= 0 && next_row < N && next_col >= 0 && next_col < N) {
            if(map[next_row][next_col] == 1 && !checked[next_row][next_col]) {
                count += dfs(next_row, next_col); 
            }
        }
    }
    return count;
}

int main(void){
    memset(checked, 0, sizeof(checked));

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!checked[i][j] && map[i][j] == 1) {
                cnt[index_cnt++] = dfs(i,j);
            }
        }
    }

    qsort(cnt, index_cnt, sizeof(int), compare);
    printf("%d\n", index_cnt);

    for(int i = 0; i < index_cnt; i++){
        printf("%d\n", cnt[i]);
    }

    return 0;

}