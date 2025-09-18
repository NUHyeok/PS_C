int lengthOfLastWord(char* s) {
    int cnt = 0;
    int A = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if (s[i] == ' ') cnt = 0;
        else {
            cnt++;
            A = cnt;
        };
    }
    return A;
}