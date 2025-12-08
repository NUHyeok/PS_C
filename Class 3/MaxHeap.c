#include <stdio.h>
#include <stdlib.h>

typedef struct MaxHeap{
    int* arr;
    int size;
    int capacity;
}MaxHeap;

MaxHeap* createMaxHeap(int capacity){
    MaxHeap* heap = (MaxHeap *)malloc(sizeof(MaxHeap));

    heap->size = 0;
    heap->capacity = capacity;
    heap->arr = (int *)malloc((capacity + 1) * sizeof(int));
    return heap;
}

void swap(int* a, int* b){
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

void insert(MaxHeap* heap, int value){
    if(heap->size == heap->capacity){
        printf("ÈüÀÌ °¡µæÂü\n");
        return 0;
    }

    int i = ++heap->size;
    heap->arr[i] = value;

    while(i > 1 && heap->arr[parent(i)] < heap->arr[i]){
        swap(&heap->arr[parent(i)], &heap->arr[i]);
        i = parent(i);
    }
}

int extractMax(MaxHeap* heap){
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
        int max_index = current;

        if(left <= heap->size && heap->arr[left] > heap->arr[max_index]){
            max_index = left;
        }
        if(right <= heap->size && heap->arr[right] > heap->arr[max_index]){
            max_index = right;
        }
        if(max_index == current)break;

        swap(&heap->arr[current], &heap->arr[max_index]);
        current = max_index;
    }
    return root;
}

