// #define LOCAL
#include <stdio.h>

#include <algorithm>
using namespace std;

class Board {
   public:
    int a, b;

    Board(){};
    Board(int a, int b) {
        this->a = a < b ? a : b;
        this->b = a + b - this->a;
    }
    bool operator==(Board board) {
        return this->a == board.a && this->b == board.b;
    }
};

int main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int num[1000];
    while (scanf("%d", &num[0]) == 1) {
        int cnt = 1;
        for (int i = 0; i < 11; i++) {
            scanf("%d", &num[i + 1]);

            bool flag = true;
            for (int j = 0; j < i + 1; j++) {
                if (num[j] == num[i + 1]) {
                    flag = false;
                    break;
                }
            }
            if (flag) cnt++;
        }

        Board boards[6];
        for (int i = 0; i < 6; i++) {
            boards[i] = Board(num[i * 2], num[2 * i + 1]);
        }

        if (cnt > 3)
            printf("IMPOSSIBLE\n");
        else if (cnt == 1)
            printf("POSSIBLE\n");
        else if (cnt == 2) {
            int cnta = 0;
            for (int i = 0; i < 12; i++) {
                if (num[i] == num[0]) cnta++;
            }
            if (cnta == 8 || cnta == 4) {
                int cnt1 = 0;
                for (int i = 0; i < 6; i++) {
                    if (boards[i].a == boards[i].b) cnt1++;
                }
                if (cnt1 == 2)
                    printf("POSSIBLE\n");
                else
                    printf("IMPOSSIBLE\n");
            } else
                printf("IMPOSSIBLE\n");
        } else {
            bool flag = true;
            for (int i = 0; i < 6; i++) {
                int cnt1 = 0;
                for (int j = 0; j < 6; j++) {
                    if (j == i) continue;
                    if (boards[i] == boards[j]) cnt1++;
                }
                bool flag1 = cnt1 == 1;
                flag &= flag1;
            }
            printf("%s", flag ? "POSSIBLE\n" : "IMPOSSIBLE\n");
        }
    }
}