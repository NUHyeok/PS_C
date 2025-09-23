#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// �� ���� -> O(nlogn)

int compare(int* a, int*b){
    return (*a - *b);
    // a-b�� ����̸� �ڸ� ����.
    // a-b�� �����̸� �ڸ����� X.
    // �������� ���� 
}

int compare_char(const void *a, const void *b){
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // qsort �Լ� ȣ��
    qsort(arr, n, sizeof(int), compare);

    // ���ĵ� �迭 ���
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}