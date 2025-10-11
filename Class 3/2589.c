#include <stdio.h>
#include <stdlib.h>
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))

int main(void){
    int N;
    scanf("%d", &N);

    int score[301] = {0};
    int dp[301] ={0};

    for (int i = 1; i < N+1; i++){
        scanf("%d", &score[i]);
    }

    if (N == 1) {
        printf("%d", score[1]);
        return 0;
    }

    if(N == 2){
        printf("%d", score[1] + score[2]);
        return 0;
    }

    dp[1] = score[1];
    dp[2] = score[1] + score[2];


    for(int i = 3; i < N+1; i++){
        int path1 = dp[i-2] + score[i];
        int path2 = dp[i-3] + score[i-1] + score[i];

        dp[i] = Max(path1, path2);
    }

    printf("%d", dp[N]);
    
    return 0;
}