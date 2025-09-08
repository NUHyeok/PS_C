#include <stdio.h>

int main(void){
    char S[100];
    scanf("%s", S);

    int A[26];
    for (int k = 0; k < 26; k++) {
        A[k] = -1;
    }
    for (int i = 0; S[i] != '\0'; i++){
        int s = S[i] - 'a';
        if (A[s] == -1){
            A[s] = i;
        }
    }

    for (int j = 0; j < 26; j ++){
        printf("%d ", A[j]);
    }

    return 0;
}