char* convertToTitle(int columnNumber) {
    char buf[10];
    int i = 0;
    while (columnNumber > 0) {
        columnNumber--; 
        buf[i++] = (columnNumber % 26) + 'A';
        columnNumber /= 26;
    }
    char* res = malloc(i + 1);
    for (int j = 0; j < i; j++) {
        res[j] = buf[i - j - 1]; 
    }
    res[i] = '\0';
    return res;
}