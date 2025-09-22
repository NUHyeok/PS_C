#include <stdio.h>
#include <string.h>
// atoi() ÇÔ¼ö -> "123" -> 123À¸·Î ¹Ù²ãÁÜ.

int main(void) {
    char s1[10], s2[10], s3[10];
    scanf("%s %s %s", s1, s2, s3);

    int n = 0;
    if (s1[0] >= '0' && s1[0] <= '9') {
        n = atoi(s1) + 3;
    } else if (s2[0] >= '0' && s2[0] <= '9') {
        n = atoi(s2) + 2;
    } else {
        n = atoi(s3) + 1;
    }

    if (n % 3 == 0 && n % 5 == 0) {
        printf("FizzBuzz\n");
    } else if (n % 3 == 0) {
        printf("Fizz\n");
    } else if (n % 5 == 0) {
        printf("Buzz\n");
    } else {
        printf("%d\n", n);
    }

    return 0;
}
