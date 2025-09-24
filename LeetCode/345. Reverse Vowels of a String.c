char* reverseVowels(char* s) {
    int A[300001] = {0};
    int is = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e'||s[i] =='E'||s[i] =='i'||s[i] =='I'||s[i] =='o'||s[i] =='O'||s[i] =='u'||s[i] =='U') {
            A[is] = i;
            is++;
        }
    }

    for(int i = 0; i < (is/2); i++){
        char temp;
        temp = s[A[i]];
        s[A[i]] = s[A[is-1-i]];
        s[A[is-1-i]] = temp;
    }

    return s;

}