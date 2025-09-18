bool isIsomorphic(char* s, char* t) {
    int cnt_s[256] = {0}, cnt_t[256] = {0};
    

    for(int i = 0; s[i] != '\0'; i++){
        if(cnt_s[(unsigned char)s[i]] != cnt_t[(unsigned char)t[i]]) return false;
        cnt_s[(unsigned char)s[i]] = i + 1;
        cnt_t[(unsigned char)t[i]] = i + 1;
    
    return true;
        
}