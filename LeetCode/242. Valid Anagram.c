bool isAnagram(char* s, char* t) {
    int A[256] = {0};

    for (int i = 0; s[i] != '\0'; i++){
        A[(unsigned int)s[i]] += 1;
        
    }
    for (int i = 0; t[i] != '\0'; i++){
        A[(unsigned int)t[i]] -= 1;
        if(A[(unsigned int)t[i]] < 0) return false;
    }

    for (int i = 0; i< 256; i++){
        if(A[i] != 0) return false;
    }
    return true;
}