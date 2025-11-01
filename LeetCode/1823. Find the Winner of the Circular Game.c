typedef struct Student{
    int id;
    struct Student *next;
    struct Student *previous;
}Student;

Student p[501];

int findTheWinner(int n, int k) {
    if(n==1) return 1;

    p[1].id = 1;
    p[1].next = &p[2];
    p[1].previous = &p[n];
    p[n].id = n;
    p[n].next = &p[1];
    p[n].previous = &p[n-1];

    for(int i = 2; i < n; i++){
        p[i].id = i;
        p[i].next = &p[i+1];
        p[i].previous = &p[i-1];
    }

    Student *current = &p[1];

    while(n > 1){
        for(int cnt = 0; cnt < k-1; cnt++){
            current = current->next;
        }

        current->previous->next = current->next;
        current->next->previous = current->previous;

        current = current->next;
        n--;
    }

    return current->id;
}

// 요세푸스 문제
/*
int findTheWinner(int n, int k) {
    int winner = 0;
    for (int i = 1; i <= n; i++) {
        winner = (winner + k) % i;
    }
    return winner + 1; // 1-인덱스로 변환
}
*/