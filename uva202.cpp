// #define LOCAL
#include <stdio.h>
#include <string.h>
#define SIZE 1000000000
int main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int *yushu = new int[SIZE];
    char *output = new char[SIZE];

    int a, b;
    while (scanf("%d%d", &a, &b) == 2) {
        printf("%d/%d = ", a, b);
        char *c = output;
        memset(output, 0, sizeof(output));
        memset(yushu, 0, sizeof(yushu));

        sprintf(c, "%d", a / b);
        while (*++c != '\0')
            ;
        *c++ = ('.');
        const char *c_mark = c;

        int *end = yushu;
        int *start = yushu;
        yushu[0] = a % b;
        bool flag = true;
        while (flag) {
            a = (*end) * 10;
            *c++ = (a / b + '0');
            *++end = a % b;
            for (int i = 0; &yushu[i] < end; i++) {
                if (yushu[i] == a % b) {
                    flag = false;
                    start = &yushu[i];
                }
            }
        }
        int n_loop = end - start;
        char *c_start;

        for (c_start = output; c_start < c - n_loop; c_start++)
            putchar(*c_start);
        putchar('(');
        for (; c_start < c_mark + 50 && c_start < c; c_start++)
            putchar(*c_start);
        if (!(c_start == c)) printf("...");
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n", n_loop);
    }
    delete[] yushu;
    delete[] output;

    return 0;
}