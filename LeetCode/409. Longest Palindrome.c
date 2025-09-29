int longestPalindrome(char* s) {
    int a[52] = {0};
    int sum = 0;
    int ex = 0;
    for(int i = 0; s[i] != '\0'; i++){
        int k;
        if((int)s[i] >= 97) {
            k = s[i] - 'a' + 26;
        }
        else {
            k = s[i] - 'A';
        }
        a[k] += 1;
    }

    for (int i = 0; i < 52; i++){
        sum += (a[i] / 2) * 2;
        if(a[i] % 2  == 1) ex = 1;
    }

    if(sum % 2 == 0) sum += ex;

    return sum;


}