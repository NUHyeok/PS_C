/*
typedef struct Event{
    int start;
    int end;
    int diff;
}Event;

int compare(const void *a, const void *b){
    Event *event1 = (Event *)a;
    Event *event2 = (Event *)b;

    if(event1->diff != event2->diff){
        return event1->diff - event2->diff;
    }

    if(event1->start != event2->start){
        return event1->start - event2->start;
    }

    return event1->end - event2->end;
}
int maxEvents(int** events, int eventsSize, int* eventsColSize) {
    Event *A = (Event *)malloc(eventsSize * sizeof(Event));
    int attend_day[100001];
    int cnt = 0;
    memset(attend_day, 0, sizeof(attend_day));

    for(int i = 0; i < eventsSize; i++){
        A[i].start = events[i][0];
        A[i].end = events[i][1];
        A[i].diff = events[i][1] - events[i][0];
    }

    qsort(A, eventsSize, sizeof(Event), compare);

    for(int i = 0; i < eventsSize; i++){
        for(int j = A[i].start; j <= A[i].end; j++){
            if(!attend_day[j]){
                attend_day[j] = 1;
                cnt++;
                break;
            }
        }
    }

    return cnt;
    
}
*/

typedef struct Event{
    int start;
    int end;
}Event;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int heap[100005];
int HeapSize = 0;

int compare(void const* a, void const* b){
    Event* event1 = (Event *)a;
    Event* event2 = (Event *)b;

    if(event1->start != event2->start){
        return event1->start - event2->start;
    }

    return event1->end - event2->end;
}
void push(int value){
    int i = ++HeapSize;
    heap[i] = value;

    while(i > 1){
        if(heap[i] < heap[i/2]){
            swap(&heap[i], &heap[i/2]);
        }
        i /= 2;
    }
}

void pop(void){
    if(HeapSize == 1){
        HeapSize--;
        return;
    }

    heap[1] = heap[HeapSize];
    HeapSize--;

    int current = 1;
    while(1){
        int left = current * 2;
        int right = current * 2 + 1;
        int small = current;

        if(left <= HeapSize && heap[left] < heap[small]){
            small = left;
        }
        if(right <= HeapSize && heap[right] < heap[small]){
            small = right;
        }
        if(small = current) break;

        swap(&heap[current], &heap[small]);
        current = small;
    }

}
int maxEvents(int** events, int eventsSize, int* eventsColSize) {
    HeapSize = 0;
    Event* A = (Event *)malloc(eventsSize * sizeof(Event));

    for(int i = 0; i < eventsSize; i++){
        A[i].start = events[i][0];
        A[i].end = events[i][1];
    }

    qsort(A, eventsSize, sizeof(Event), compare);

    int count = 0;
    int day = 0;
    int i = 0;

    while(i < eventsSize || HeapSize > 0){
        if(HeapSize == 0 && day < A[i].start) day = A[i].start;

        while(i < eventsSize && A[i].start == day){
            push(A[i].end);
            i++;
        }

        while (HeapSize > 0 && heap[1] < day) {
            pop();
        }

        if (HeapSize > 0) {
            pop();
            count++;
        }

        day++;
    }

    free(A);
    return count;

}