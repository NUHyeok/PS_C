char invert(char a){
    if (a == '1') return '0';
    return '1';
}
char* reverse(char *a){
    int len = strlen(a);
    char *r = (char*)malloc(len + 1);;
    int j = 0;
    for(int i = strlen(a)-1; i >= 0; i--){
        r[j++] = invert(a[i]);
    }
    r[j] = '\0';
    return r;
}

char* s (int n){
    if(n == 1) {
        char *s1 = (char*)malloc(2);
        strcpy(s1, "0");
        return s1;
    }
    char *s_prev = s(n-1);
    char *rev = reverse(s_prev);
    int len = 2 * strlen(s_prev) + 1;
    char *result = (char *)malloc(len + 1);

    strcpy(result, s_prev);
    strcat(result, "1");
    strcat(result, rev);
    
    free(s_prev);
    free(rev);

    return result;
}
char findKthBit(int n, int k) {
    char *ans = s(n);
    return ans[k-1];
}

// 효율적인 코드

/*
char findKthBit(int n, int k) {
    if(n==1) return '0';

    int i = 1 << (n-1); // 2 ^ n-1

    if(k < i) return findKthBit(n-1,k);
    else if(k == i) return '1';
    else return '0' + '1' - findKthBit(n-1, (1 << n) - k);
}
*/