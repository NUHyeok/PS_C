#define MAX(a, b) ((a) > (b) ? (a) : (b))

int rows, cols;
int memo[201][201];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int r, int c, int** matrix){
    if(memo[r][c] != 0) return memo[r][c];

    int max_len = 1;

    for(int i = 0; i < 4; i++){
        int nr = r + dx[i];
        int nc = c + dy[i];

        // 범위 체크 && 증가하는 경로인지 체크
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] > matrix[r][c]) {
            
            // 재귀 호출로 이웃의 최대 길이를 가져옴
            int len = 1 + dfs(nr, nc, matrix);
            max_len = MAX(max_len, len);
        }
        
    }
    memo[r][c] = max_len;
    return max_len;
}
int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    rows = matrixSize;
    cols = matrixColSize[0];
    
    memset(memo, 0, sizeof(memo));
    int global_max = 0;

    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixColSize[0]; j++){
            int len = dfs(i, j, matrix);
            global_max = MAX(global_max, len);
        }
    }

    return global_max;
}