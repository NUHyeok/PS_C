int firstUniqChar(char* s) {
    int a[26];

    for(int i = 0; i < 26; i++) {
        a[i] = -1;
    }

    int min_index = 100001;

    for(int i = 0; s[i] != '\0'; i++){
        int k = s[i] - 'a';
        if(a[k] == -1) a[k] = i;
        else a[k] = -2;
    }

    for (int i = 0; i < 26; i++){
        if(a[i] > -1){
            if(min_index > a[i]) min_index = a[i];
        }
    }
    
    if(min_index == 100001) return -1;

    return min_index;
}