#define LOCAL
#include <math.h>
#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int max(int a, int b) { return a > b ? a : b; }

int dist2(int x1, int y1, int x2, int y2) {
    int a = x1 - x2, b = y1 - y2;
    return a * a + b * b;
}

bool dead(int X, int Y, int N, char role[], int x[], int y[]) {
    // 存在一个piece将死则死
    bool flag = false;
    // 一个piece
    for (int i = 0; i < N; i++) {
        bool flag_piece = true;
        char piece = role[i];
        int x_p = x[i];
        int y_p = y[i];
        if (piece == 'G') {
            if (Y == y_p) {
                for (int j = 0; j < N; j++) {
                    if (y[j] == Y && x[j] < x_p && x[j] > X) flag_piece = false;
                }
            } else
                flag_piece = false;
        }

        // 车
        else if (piece == 'R') {
            if (x_p == X) {
                for (int j = 0; j < N; j++) {
                    if (x[j] == X && y[j] > min(y_p, Y) && y[j] < max(y_p, Y))
                        flag_piece = false;
                }
            } else if (y_p == Y) {
                for (int j = 0; j < N; j++) {
                    if (y[j] == Y && x[j] > min(x_p, X) && x[j] < max(x_p, X))
                        flag_piece = false;
                }
            } else
                flag_piece = false;
        }

        // 马
        else if (piece == 'H') {
            if (dist2(x_p, y_p, X, Y) == 5) {
                // 蹩马腿
                for (int j = 0; j < N; j++) {
                    if (dist2(x_p, y_p, x[j], y[j]) == 1 &&
                        dist2(x[j], y[j], X, Y) == 2)
                        flag_piece = false;
                }
            } else
                flag_piece = false;

        }

        // 炮
        else if (piece == 'C') {
            if (x_p == X) {
                int middle = 0;
                for (int j = 0; j < N; j++) {
                    if (x[j] == X && y[j] < max(y_p, Y) && y[j] > min(y_p, Y))
                        middle++;
                }
                if (middle != 1) flag_piece = false;
            } else if (y_p == Y) {
                int middle = 0;
                for (int j = 0; j < N; j++) {
                    if (y[j] == Y && x[j] < max(x_p, X) && x[j] > min(x_p, X))
                        middle++;
                }
                if (middle != 1) flag_piece = false;
            } else
                flag_piece = false;
        } else
            flag_piece = false;

        flag |= flag_piece;
    }
    return flag;
}

int main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int N, X, Y;
    while (scanf("%d%d%d", &N, &X, &Y) == 3 && N != 0) {
        char role[10];
        int x[10], y[10];
        getchar();
        for (int i = 0; i < N; i++) {
            char temp[5];
            scanf("%s%d%d", temp, &x[i], &y[i]);
            role[i] = temp[0];
            getchar();
        }
        int gx, gy;
        for (int i = 0; i < N; i++) {
            if (role[i] == 'G') {
                gx = x[i];
                gy = y[i];
            }
        }
        // 反杀
        bool kill = true;
        if (Y == gy) {
            for (int i = 0; i < N; i++) {
                if (y[i] == Y && x[i] < max(X, gx) && x[i] > min(X, gx))
                    kill = false;
            }
        } else
            kill = false;
        bool is_dead = !kill;
        if (is_dead) {
            // 全true 为死
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (abs(i) + abs(j) != 1) continue;
                    int X_now = X + i;
                    int Y_now = Y + j;
                    if (X_now < 1 || X_now > 3 || Y_now < 4 || Y_now > 6)
                        continue;
                    for (int k = 0; k < N; k++) {
                        if (x[k] == X_now && y[k] == Y_now) {
                            role[k] = 'Z';
                        }
                    }
                    is_dead &= dead(X_now, Y_now, N, role, x, y);
                }
            }
        }

        printf("%s", is_dead ? "YES\n" : "NO\n");
    }
    return 0;
}