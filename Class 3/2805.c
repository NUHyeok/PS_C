#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    long long *height = (long long *)malloc(N * sizeof(long long));
    long long max = 0, min = 0;
    for(int i = 0; i < N; i++){
        scanf("%lld", &height[i]);
        if(max < height[i]) max = height[i];
    }
    long long max_value = 0;
    while(min <= max){
        long long value = 0;
        long long mid = (min + max) / 2;

        for(int i = 0; i < N; i++){
            if (height[i] >= mid) value += height[i] - mid;
        }

        if(value >= M){
            max_value = mid;
            min = mid + 1;
        }
        else{
            max = mid - 1;
        }
    }

    free(height);

    printf("%lld", max_value);
    return 0;


}