#include <stdio.h>
#include <string.h>

// #define LOCAL
int main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int puzzle_i = 0;
    // 读数据
    char frame[10][10];
    while (fgets(frame[0], 10, stdin)) {
        if (strlen(frame[0]) < 4 && frame[0][0] == 'Z') break;
        for (int i = 1; i <= 4; i++) {
            fgets(frame[i], 10, stdin);
        }
        char opt;
        bool valid = true;

        // 找空格
        int x = 0, y = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (frame[i][j] == ' ' || frame[i][j] == '\n') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        // 读&&处理操作
        while ((opt = getchar()) != '0') {
            if (opt == 'A') {
                if (x - 1 < 0) {
                    valid = false;
                    continue;
                }
                frame[x][y] = frame[x - 1][y];
                x--;
                frame[x][y] = ' ';

            } else if (opt == 'B') {
                if (x + 1 > 4) {
                    valid = false;
                    continue;
                }
                frame[x][y] = frame[x + 1][y];
                x++;
                frame[x][y] = ' ';
            }

            else if (opt == 'L') {
                if (y - 1 < 0) {
                    valid = false;
                    continue;
                }
                frame[x][y] = frame[x][y - 1];
                y--;
                frame[x][y] = ' ';
            } else if (opt == 'R') {
                if (y + 1 > 4) {
                    valid = false;
                    continue;
                }
                frame[x][y] = frame[x][y + 1];
                y++;
                frame[x][y] = ' ';
            } else if (opt != '\n') {
                valid = false;
                continue;
            }
        }
        char _[100];
        fgets(_, 100, stdin);

        // 输出
        if (puzzle_i) printf("\n");
        printf("Puzzle #%d:\n", ++puzzle_i);
        if (!valid)
            printf("This puzzle has no final configuration.\n");
        else
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 4; j++) printf("%c ", frame[i][j]);
                printf("%c\n", frame[i][4]);
            }
    }
    return 0;
}
