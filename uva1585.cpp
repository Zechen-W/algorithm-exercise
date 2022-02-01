#include <string.h>

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        char s[85];
        scanf("%s", s);
        int score = 0;
        int sum = 0;
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == 'O') {
                sum += ++score;
            } else
                score = 0;
        }
        printf("%d\n", sum);
    }
}