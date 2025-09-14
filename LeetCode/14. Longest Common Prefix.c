char* longestCommonPrefix(char** strs, int strsSize) {
    char* prefix = malloc(200);
    strcpy(prefix, strs[0]);
    
    for (int i = 1; i < strsSize; i++){
        int j = 0;
        while (prefix[j] != '\0' && strs[i][j] != '\0' && prefix[j] == strs[i][j]){
            j++;
        }
        prefix[j] = '\0';
        
    }
    return prefix;
}