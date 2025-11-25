typedef struct MinHeap {
    int arr[2500];
    int size;
}MinHeap;

typedef struct MaxHeap {
    int arr[2500];
    int size;
}MaxHeap;

typedef struct {
    MinHeap minheap;
    MaxHeap maxheap;

} MedianFinder;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

MedianFinder* medianFinderCreate() {
    MedianFinder *M = (MedianFinder *)malloc(sizeof(MedianFinder *));
    M->minheap.size = 0;
    M->maxheap.size = 0;

    return M;
    
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if(obj->minheap.size > obj->maxheap.size){
        int i = ++obj->maxheap.size;
        obj->maxheap.arr[i] = num;

        while(i > 1 && obj->maxheap.arr[i/2] < obj->maxheap.arr[i]){
            swap(&obj->maxheap.arr[i/2], &obj->maxheap.arr[i]);
            i /= 2;
        }
    }
    else{
        int i = ++obj->minheap.size;
        obj->minheap.arr[i] = num;

        while(i > 1 && obj->minheap.arr[i/2] > obj->minheap.arr[i]){
            swap(&obj->minheap.arr[i/2], &obj->minheap.arr[i]);
            i /= 2;
        }
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if(obj->minheap.size == obj->maxheap.size){
        return (double)obj->maxheap.arr[1] / (double)obj->minheap.arr[1];
    }
    return (double)obj->minheap.arr[1];
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/