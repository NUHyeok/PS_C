#include <stdio.h>
#include <math.h>

int main(void){
    int N;
    static int cnt[8001] = {0};     
    long long sum = 0;              
    scanf("%d", &N);

    int x;
    for (int i = 0; i < N; i++){
        scanf("%d", &x);
        cnt[x + 4000]++;            
        sum += x;
    }

    int avg = (int)llround((double)sum / N); 
    if (avg == -0) avg = 0; 

    int target = (N + 1) / 2;
    int cumul = 0;
    int median = 0;
    for (int i = 0; i <= 8000; i++){
        cumul += cnt[i];
        if (cumul >= target){
            median = i - 4000;
            break;
        }
    }

    int maxfreq = 0;
    for (int i = 0; i <= 8000; i++){
        if (cnt[i] > maxfreq) maxfreq = cnt[i];
    }
    int mode = 0;
    int found_once = 0; 
    for (int i = 0; i <= 8000; i++){
        if (cnt[i] == maxfreq){
            if (!found_once){
                mode = i - 4000;    
                found_once = 1;
            } else {
                mode = i - 4000;    
                break;
            }
        }
    }

    // 4) 범위: 마지막 등장 - 처음 등장
    int min_idx = -1, max_idx = -1;
    for (int i = 0; i <= 8000; i++){
        if (cnt[i] > 0){ min_idx = i; break; }
    }
    for (int i = 8000; i >= 0; i--){
        if (cnt[i] > 0){ max_idx = i; break; }
    }
    int range = (max_idx - min_idx);

    printf("%d\n", avg);
    printf("%d\n", median);
    printf("%d\n", mode);
    printf("%d\n", range);

    return 0;
}
