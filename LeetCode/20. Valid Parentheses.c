bool isValid(char* s) {
    char A[10001];
    int cnt = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if (cnt < 0){
            return false;
        }

        if(s[i] == '[' || s[i] == '{' || s[i] == '('){
            A[cnt] = s[i];
            cnt++;
        }
        else{
            if (cnt == 0){
            return false;
            }
            if(s[i] == ']'){
                if(A[cnt-1] == '['){
                    cnt--;
                }
                else{
                    return false;
                }
            }
            else if(s[i] == ')'){
                if(A[cnt-1] == '('){
                    cnt--;
                }
                else{
                    return false;
                }
            }
            else if(s[i] == '}'){
                if(A[cnt-1] == '{'){
                    cnt--;
                }
                else{
                    return false;
                }
            }

        }
        
    }
    if (cnt == 0){
        return true;
    }
    else{
        return false;
    }
}