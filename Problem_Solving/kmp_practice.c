#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void make_lps(char *pat, int M, int *lps){
    int length = 0;
    lps[0] = 0;

    int i = 1;
    while(i < M){
        if(pat[i] == pat[length]){
            length++;
            lps[i] = length;
            i++;
        }
        else if{
            if(length > 0){
                length = lps[length-1];
            }
            else{
                lps[i] =0;
                i++;
            }
        }
    }
}

void KMP(char *txt, char *pat){
    int N = strlen(txt);
    int M = strlen(pat);

    int *lps = (int *)malloc(sizeof(int) * M);

    make_lps(pat, M, lps);

    int i = 0, j = 0;

    while(i < N){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }
        if(j == M){
            printf("%d", i);
            j = lps[j-1];
        }
        
        else if(i < N && txt[i] != pat[j]){
            if(j != 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
    }
}