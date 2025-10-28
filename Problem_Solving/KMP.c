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
            printf("������ %d �ε������� ã�ҽ��ϴ�.\n", i - j);
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
    
    printf("�ؽ�Ʈ: %s\n", txt);
    printf("����: %s\n", pat);
    
    KMP(txt, pat);
    
    printf("\n--- �ٸ� ���� ---\n");
    char txt2[] = "BACBABABA";
    char pat2[] = "ABABCA";

    printf("�ؽ�Ʈ: %s\n", txt2);
    printf("����: %s\n", pat2);
    KMP(txt2, pat2); // (�� ������ �ƹ��͵� ��� �� �ϴ°� �½��ϴ�)

    return 0;
}