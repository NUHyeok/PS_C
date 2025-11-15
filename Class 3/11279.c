#include <stdio.h>
#include <stdlib.h>

void insert(long long *MaxHeap, long long value, int *size){
    (*size)++;
    int i = *size;
    MaxHeap[i] = value;

    while(i > 1 && MaxHeap[i] > MaxHeap[i / 2]){
        long long temp = MaxHeap[i];
        MaxHeap[i] = MaxHeap[i/2];
        MaxHeap[i/2] = temp;
        i /= 2;
    }
}

long long extractMax(long long *MaxHeap, int *size){
    if(*size == 0) return 0;

    long long ans = MaxHeap[1];
    MaxHeap[1] = MaxHeap[*size];
    (*size)--;

    int current = 1;
    while(1){
        int left = current * 2;
        int right = current * 2 + 1;
        int max_value = current;

        if(left <= *size && MaxHeap[left] >= MaxHeap[max_value]){
            max_value = left;
        }
        if(right <= *size && MaxHeap[right] >= MaxHeap[max_value]){
            max_value = right;
        }
        if(current == max_value) break;

        long long temp = MaxHeap[current];
        MaxHeap[current] = MaxHeap[max_value];
        MaxHeap[max_value] = temp;

        current = max_value;
    }
    return ans;
}

int main(void){
    int N;
    int size = 0;
    scanf("%d", &N);

    long long *MaxHeap = (long long *)malloc((N+1) * sizeof(long long));

    for(int i = 0; i < N; i++){
        long long a;
        scanf("%lld", &a);

        if(a == 0) printf("%lld\n", extractMax(MaxHeap, &size));
        else insert(MaxHeap, a, &size);
    }

    return 0;

}