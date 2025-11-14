#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap {
    int *arr;
    int size;
    int capacity;
}MinHeap;

MinHeap* createMinHeap(int capacity){
    MinHeap* heap = (MinHeap *)malloc(sizeof(MinHeap));
    
    heap->size = 0;
    heap->capacity = capacity;
    heap->arr = (int *)malloc((capacity + 1) * sizeof(int));
    return heap;
}

void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i){
    return i / 2;
}

int leftChild(int i){
    return i * 2;
}

int rightChild(int i){
    return i * 2 + 1;
}

void insert(MinHeap *heap, int value){
    if (heap->size == heap->capacity){
        printf("ÈüÀÌ °¡µæ Ã¡½À´Ï´Ù\n");
        return;
    }

    int i = ++heap->size;
    heap->arr[i] = value;

    while(i > 1 && heap->arr[parent(i)] > heap->arr[i]){
        swap(&heap->arr[i], &heap->arr[parent(i)]);
        i = parent(i);
    }

}

int extractMin(MinHeap *heap){
    int root = heap->arr[1];
    if(heap->size == 1){
        heap->size--;
        return root;
    }

    heap->arr[1] = heap->arr[heap->size];
    heap->size--;

    int current = 1;
    while(1){
        int left = leftChild(current);
        int right = rightChild(current);
        int smallest = current;

        if(left <= heap->size && heap->arr[left] < heap->arr[smallest]){
            smallest = left;
        }
        if(right <= heap->size && heap->arr[right] < heap->arr[smallest]){
            smallest = right;
        }
        if(smallest = current) break;

        swap(&heap->arr[current], &heap->arr[smallest]);
        current = smallest;
    }
    return root;
}