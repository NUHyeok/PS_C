typedef struct Heap {
    int arr[50001];
    int size;
}Heap;

typedef struct {
    Heap minheap;
    Heap maxheap;

} MedianFinder;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push_max(Heap *h, int num) {
    int i = ++(h->size);
    h->arr[i] = num;
    while (i > 1 && h->arr[i/2] < h->arr[i]) {
        swap(&h->arr[i/2], &h->arr[i]);
        i /= 2;
    }
}

int pop_max(Heap *h) {
    int ret = h->arr[1];
    h->arr[1] = h->arr[h->size--];
    int i = 1;
    while (i * 2 <= h->size) {
        int child = i * 2;
        if (child + 1 <= h->size && h->arr[child] < h->arr[child+1]) {
            child++;
        }
        if (h->arr[i] >= h->arr[child]) break;
        swap(&h->arr[i], &h->arr[child]);
        i = child;
    }
    return ret;
}

void push_min(Heap *h, int num) {
    int i = ++(h->size);
    h->arr[i] = num;
    while (i > 1 && h->arr[i/2] > h->arr[i]) {
        swap(&h->arr[i/2], &h->arr[i]);
        i /= 2;
    }
}

int pop_min(Heap *h) {
    int ret = h->arr[1];
    h->arr[1] = h->arr[h->size--];
    int i = 1;
    while (i * 2 <= h->size) {
        int child = i * 2;
        if (child + 1 <= h->size && h->arr[child] > h->arr[child+1]) {
            child++;
        }
        if (h->arr[i] <= h->arr[child]) break;
        swap(&h->arr[i], &h->arr[child]);
        i = child;
    }
    return ret;
}
MedianFinder* medianFinderCreate() {
    MedianFinder *M = (MedianFinder *)malloc(sizeof(MedianFinder));
    M->minheap.size = 0;
    M->maxheap.size = 0;

    return M;
    
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->maxheap.size == 0 || num <= obj->maxheap.arr[1]) {
        push_max(&obj->maxheap, num);
    } else {
        push_min(&obj->minheap, num);
    }

    if (obj->maxheap.size > obj->minheap.size + 1) {
        push_min(&obj->minheap, pop_max(&obj->maxheap));
    }
    else if (obj->minheap.size > obj->maxheap.size) {
        push_max(&obj->maxheap, pop_min(&obj->minheap));
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if(obj->minheap.size == obj->maxheap.size){
        return ((double)obj->maxheap.arr[1] + (double)obj->minheap.arr[1]) / 2;
    }
    return (double)obj->maxheap.arr[1];
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