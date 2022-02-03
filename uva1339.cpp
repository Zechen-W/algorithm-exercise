// #define LOCAL

#include <stdio.h>
#include <string.h>

#include <algorithm>

int cnt(int *f, char s[]) {
    int *p = f;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') continue;
        const char origin = s[i];
        for (int j = i; j < strlen(s); j++) {
            if (s[j] == origin) {
                (*p)++;
                s[j] = ' ';
            }
        }
        p++;
    }
    return p - f;
}
int main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    char s1[105], s2[105];
    while (scanf("%s%s", s1, s2) == 2) {
        int f1[100], f2[100];
        memset(f1, 0, sizeof(f1));
        memset(f2, 0, sizeof(f2));

        int c1 = cnt(f1, s1);
        int c2 = cnt(f2, s2);
        std::sort(f1, f1 + c1);
        std::sort(f2, f2 + c2);
        bool flag = true;
        for (int i = 0; i < c1; i++) {
            if (f1[i] != f2[i]) {
                flag = false;
                break;
            }
        }
        printf("%s", flag ? "YES\n" : "NO\n");
    }
    return 0;
}