typedef struct Event{
    int time;
    int type;
}Event;

int compare(const void* a, const void* b) {
    Event* ev1 = (Event*)a;
    Event* ev2 = (Event*)b;
    
    if (ev1->time != ev2->time) {
        return ev1->time - ev2->time;
    }
    
    return ev1->type - ev2->type;
}

int minGroups(int** intervals, int intervalsSize, int* intervalsColSize) {
    Event* events = (Event *)malloc(intervalsSize * 2 *sizeof(Event));

    for(int i = 0; i < intervalsSize; i++){
        events[2 * i].time = intervals[i][0];
        events[2 * i].type = 1;

        events[2 * i + 1].time = intervals[i][1] + 1;
        events[2 * i + 1].type = -1;
    }
    qsort(events, intervalsSize * 2, sizeof(Event), compare);

    int max_groups = 0;
    int current_groups = 0;

    for (int i = 0; i < intervalsSize * 2; i++) {
        current_groups += events[i].type;
        
        if (current_groups > max_groups) {
            max_groups = current_groups;
        }
    }
    
    free(events);
    return max_groups;


}