// #define LOCAL
#define MAXLEN 100000

#include <stdio.h>
#include <string.h>

bool find(char *sub, char *str) {
    bool flag = false;

    if (strlen(sub) == 1) {
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == sub[0]) {
                flag = true;
                break;
            }
        }
        return flag;
    }

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == sub[0] && !flag) {
            flag |= find(sub + 1, str + i + 1);
        }
    }
    return flag;
}

int main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    char s[MAXLEN], t[MAXLEN];
    while (scanf("%s", s) != EOF) {
        scanf("%s", t);
        printf("%s", find(s, t) ? "Yes\n" : "No\n");
    }
    return 0;
}
