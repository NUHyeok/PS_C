#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++){
        int H, W, N, Y, X;
        scanf("%d %d %d", &H, &W, &N);

        X = (N-1) / H + 1;
        Y = (N -1) % H + 1;
        
        printf("%d%02d\n", Y, X);


    }
    return 0;
}