#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(long long *a, long long *b){
    long long temp = *a;
    *a = *b;
    *b = temp;
}

void insert(long long *MinHeap, long long value, int *size){
    (*size)++;
    int index = *size;
    MinHeap[index] = value;

    while(index > 1){
        int parent_index = index / 2;

        long long child_val = MinHeap[index];
        long long parent_val = MinHeap[parent_index];

        if(abs(child_val) < abs(parent_val)){
            swap(&MinHeap[index], &MinHeap[parent_index]);
            index = parent_index;
        }
        else if(abs(child_val) == abs(parent_val) && child_val < parent_val){
            swap(&MinHeap[index], &MinHeap[parent_index]);
            index = parent_index;
        }
        else{
            break;
        }
    }
}
long long extract_min(long long *MinHeap, int *size){
    if (*size == 0) {
        return 0;
    }
    long long ans = MinHeap[1];
    MinHeap[1] = MinHeap[*size];
    (*size)--;

    int current = 1;
    while (1){
        int left_child = current * 2;
        int right_child = current * 2 + 1;
        int smallest = current;

        if(left_child <= *size){
            long long parent_val = MinHeap[current];
            long long left_val = MinHeap[left_child];

            if(abs(left_val) < abs(parent_val)) smallest = left_child;
            else if(abs(left_val) == abs(parent_val) && left_val < parent_val){
                smallest = left_child;
            }
        }

        if(right_child <= *size){
            long long small = MinHeap[smallest];
            long long right_val = MinHeap[right_child];

            if(abs(right_val) < abs(small)) smallest = right_child;
            else if(abs(right_val) == abs(small) && right_val < small){
                smallest = right_child;
            }
        }

        if(smallest == current) break;
        swap(&MinHeap[current], &MinHeap[smallest]);
        current = smallest;


    }
    return ans;

    
}



int main(void){
    int N;
    int size = 0;
    scanf("%d", &N);

    long long *MinHeap = (long long *)malloc((N+1) * sizeof(long long));

    for(int i = 0; i < N; i++){
        long long a;
        scanf("%lld", &a);
        if(a == 0) {
            printf("%lld\n", extract_min(MinHeap, &size));
        }
        else insert(MinHeap,a, &size);
    }
    return 0;
}