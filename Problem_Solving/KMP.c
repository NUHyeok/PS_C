#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void make_lps(char *pat, int M, int* lps){
    int length = 0;
    lps[0] = 0;

    int i = 1;
    while(i < M){
        if(pat[i] == pat[length]){
            length++;
            lps[i] = length;
            i++;
        }
        else{
            if(length != 0){
                length = lps[length-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(char *txt, char* pat){
    int N = strlen(txt);
    int M = strlen(pat);

    int *lps = (int *)malloc(M * sizeof(int));

    make_lps(pat, M, lps);

    int i = 0, j = 0;

    while(i < N){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }

        if(j == M){
            printf("패턴을 %d 인덱스에서 찾았습니다.\n", i - j);
            j = lps[j-1];
        }

        else if(i < N && pat[j] != txt[i]){
            if(j != 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }

    }
    free(lps);
}

int main() {
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    
    printf("텍스트: %s\n", txt);
    printf("패턴: %s\n", pat);
    
    KMP(txt, pat);
    
    printf("\n--- 다른 예시 ---\n");
    char txt2[] = "BACBABABA";
    char pat2[] = "ABABCA";

    printf("텍스트: %s\n", txt2);
    printf("패턴: %s\n", pat2);
    KMP(txt2, pat2); // (이 예제는 아무것도 출력 안 하는게 맞습니다)

    return 0;
}