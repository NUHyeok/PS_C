char* removeKdigits(char* num, int k) {
    char stack[100000];
    int top = -1;
    

    for(int i = 0; num[i] != '\0' && k >= 0; i++){
        while(k > 0 && top >= 0 && stack[top] > num[i]){
            top--;
            k--;
        }
        stack[++top] = num[i];
    }

    top -= k;
    stack[top + 1] = '\0';
    int start = 0;
    while(stack[start] == '0' && start <= top){
        start++;
    }

    if(start > top){
        return "0";
    }

    char *result = malloc(strlen(num)+1);
    strcpy(result, stack + start);
    return result;
}