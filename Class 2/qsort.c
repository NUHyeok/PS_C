#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 퀵 정렬 -> O(nlogn)

int compare(int* a, int*b){
    return (*a - *b);
    // a-b가 양수이면 자리 변경.
    // a-b가 음수이면 자리변경 X.
    // 오름차순 정렬 
}

int compare_char(const void *a, const void *b){
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // qsort 함수 호출
    qsort(arr, n, sizeof(int), compare);

    // 정렬된 배열 출력
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}