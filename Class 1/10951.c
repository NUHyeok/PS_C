#include <stdio.h>

int main(void) {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) { // 입력이 멈추면 종료
        printf("%d\n", a + b);
    }
    return 0;
}
