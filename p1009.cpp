#include <stdio.h>
#include <string.h>

#include <iostream>
using namespace std;
class Gjd {
   public:
    char* num;
    Gjd() {
        this->num = new char[1000];
        // printf("构造函数\n");
        // printf("%x\n", this);
        memset(this->num, 0, sizeof(this->num));
    }
    Gjd(const Gjd& a) {
        this->num = new char[1000];
        memset(this->num, 0, sizeof(this->num));
        // printf("复制构造函数\n");
        // printf("%x\n", this);
        // printf("%x\n", &a);
        // memcpy(this->num, a.num, sizeof(this->num));
        for (int i = 0; i <= strlen(a.num); i++) this->num[i] = a.num[i];
    }
    ~Gjd() {
        // printf("析构函数\n");
        // printf("%x\n", this);
        delete[] this->num;
    }
    Gjd operator+(const Gjd& a) {
        char* p = this->num;
        char* q = a.num;
        Gjd res;
        char* r = res.num;
        int jinwei = 0;
        while (*p || *q || jinwei) {
            int temp = jinwei;
            if (*p) temp += *p++ - '0';
            if (*q) temp += *q++ - '0';
            *r++ = temp % 10 + '0';
            jinwei = temp / 10;
        }
        *r = '\0';
        return res;
    }
    Gjd operator*(int a) {
        Gjd res;
        char* r = res.num;
        if (a >= 11) return (*this * (a / 10)) * 10 + *this * (a % 10);
        if (a == 10) {
            res.num[0] = '0';
            for (int i = 0; i <= strlen(this->num); i++)
                res.num[i + 1] = this->num[i];
            return res;
        }
        char* p = this->num;
        int jinwei = 0;
        while (jinwei || *p) {
            int temp = jinwei;
            if (*p) temp += (*p++ - '0') * a;
            *r++ = temp % 10 + '0';
            jinwei = temp / 10;
        }
        *r = '\0';
        return res;
    }
    void operator=(const Gjd& a) {
        for (int i = 0; i <= strlen(a.num); i++) this->num[i] = a.num[i];
    }
    void print(void) {
        char* p = this->num;
        while (*p) p++;
        p--;
        while (p >= this->num) printf("%c", *p--);
    }
};

Gjd* jc(int n) {
    Gjd* res = new Gjd[n + 5];
    res[1].num[0] = '1';
    for (int i = 2; i <= n; i++) {
        res[i] = res[i - 1] * i;
    }
    return res;
}

int main() {
    int n;
    // scanf("%d", &n);
    cin >> n;
    Gjd* nums = jc(n);
    Gjd S;
    for (int i = 1; i <= n; i++) {
        S = S + nums[i];
    }
    S.print();
    delete[] nums;
    return 0;
}