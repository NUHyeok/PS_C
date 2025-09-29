#include <string.h>

bool isSubsequence(char* s, char* t) {
    if(strlen(s) > strlen(t)) return false;

    int start_index = 0;
    for(int i = 0; s[i] != '\0'; i++){
        int is = 1;
        for(int j = start_index; t[j] != '\0'; j++){
            if(s[i] == t[j]){
                start_index = j+1;
                is = 0;
                break;
            }
        }
        if (is) return false;
    }

    return true;
}