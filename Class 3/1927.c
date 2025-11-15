#include <stdio.h>
#include <stdlib.h>

void insert(long long *MinHeap, long long value, int *size){
    (*size)++;
    int i = *size;
    MinHeap[i] = value;

    while(i > 1 && MinHeap[i] < MinHeap[i / 2]){
        long long temp = MinHeap[i];
        MinHeap[i] = MinHeap[i / 2];
        MinHeap[i/2] = temp;

        i /= 2;
    }


}

long long extractMin(long long *MinHeap,int *size){
    if(*size == 0) return 0;

    long long ans = MinHeap[1];
    MinHeap[1] = MinHeap[*size];
    (*size)--;

    int current = 1;
    while(1){
        int left = 2 * current;
        int right = 2 * current + 1;
        int smallest = current;

        if(left <= *size && MinHeap[left] < MinHeap[smallest]){
            smallest = left;
        }
        if(right <= *size && MinHeap[right] < MinHeap[smallest]){
            smallest = right;
        }
        if(smallest == current) break;

        long long temp = MinHeap[current];
        MinHeap[current] = MinHeap[smallest];
        MinHeap[smallest] = temp;

        current = smallest;
    }
    return ans;
}

int main(void){
    int N;
    int size = 0;
    scanf("%d", &N);
    long long *MinHeap = (long long *)malloc((N+1) * sizeof(long long));

    for(int i = 0 ; i < N; i++){
        long long a;
        scanf("%lld", &a);

        if(a == 0) printf("%lld\n", extractMin(MinHeap, &size));
        else insert(MinHeap, a, &size);
    }
    return 0;
}