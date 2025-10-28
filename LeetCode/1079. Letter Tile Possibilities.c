int dfs(int *A){
    int current_sum = 0;
    for(int i = 0; i < 26; i++){
        if(A[i] > 0){
            current_sum++;
            A[i]--;
            current_sum += dfs(A);
            A[i]++;
        }
    }
    return current_sum;
}
int numTilePossibilities(char* tiles) {
    int A[26] = {0};
    for(int i = 0; tiles[i] != '\0'; i++){
        A[tiles[i] - 'A'] += 1;
    }

    return dfs(A);
}