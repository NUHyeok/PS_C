int lengthOfLongestSubstring(char* s) {
    int best = 0;
    

    for(int i = 0; s[i] != '\0'; i++){
        int A[256] = {0};
        int ing = 0;
        for(int j = i; s[j] != '\0'; j++){
            if(A[s[j]] == 0){
                ing++;
                A[s[j]] = 1;
            }
            else{
                break;
            }
        }
        if(ing > best){
            best = ing;
        }
    }
    return best;
}