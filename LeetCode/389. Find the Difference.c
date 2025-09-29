char findTheDifference(char* s, char* t) {
    int a[26] = {0};
    char ans;

    for(int i = 0; t[i] != '\0'; i++){
        int k = t[i] - 'a';
        a[k] += 1;
        if(s[i] != '\0'){
            k = s[i] - 'a';
            a[k] -= 1;
        }
    }

    for(int i = 0; i < 26; i++){
        if(a[i] == 1){
            ans = i + 'a';
        }
    }

    return ans;
}