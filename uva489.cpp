#define LOCAL
#include <stdio.h>
#include <string.h>
void check(char guess, char* org, int& life, int& left, bool* wrong) {
    char* p = org;
    bool correct = false;
    for (; *p != '\0'; p++) {
        if (*p == guess) {
            correct = true;
            *p = ' ';
            left--;
        }
    }
    if (!correct && !wrong[guess - 'a']) {
        life--;
        wrong[guess - 'a'] = true;
    }
}
int main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int kase;
    char org[100], guess[100];
    while (scanf("%d%s%s", &kase, org, guess) == 3 && kase != -1) {
        printf("Round %d\n", kase);
        int life = 7;
        int left = strlen(org);
        bool wrong_guessed[30];
        memset(wrong_guessed, false, sizeof(wrong_guessed));
        for (int i = 0; i < strlen(guess); i++) {
            check(guess[i], org, life, left, wrong_guessed);
            if (life == 0 || left == 0) break;
        }
        if (life == 0)
            printf("You lose.\n");
        else if (left == 0)
            printf("You win.\n");
        else
            printf("You chickened out.\n");
    }
    return 0;
}