#include <cstring>
#include <iostream>

using namespace std;

int findfb(char *num) {
    for (int i = 0;; i++) {
        if (num[i] == '.' || num[i] == 0) {
            return i;
        }
    }
    return -1;
}
int findfs(char *num) {
    for (int i = 0; num[i]; i++) {
        if (num[i] != '.' && num[i] != '0') {
            return i;
        }
    }
    return -1;
}

int getexp(int sb, int fb) {
    if (sb == -1) {
        return 0;
    }
    return sb > fb ? fb - sb + 1 : fb - sb;
}

void preb(char *num, char *buffer, int sb, int max) {
    int i;
    if (sb == -1) {
        for (i = 0; i < max; i++) {
            buffer[i] = '0';
        }
    } else {
        bool zero = false;
        for (i = 0; i < max; i++) {
            if (zero) {
                buffer[i] = '0';
            } else {
                if (num[i + sb] == 0) {
                    buffer[i] = '0';
                    zero = true;
                } else if (num[i + sb] == '.') {
                    i--, sb++;  //跳过小数点
                } else {
                    buffer[i] = num[i + sb];
                }
            }
        }
    }
    buffer[i] = 0;
}

int main() {
    int n;
    char a[1000], b[1000];
    scanf("%d %s %s", &n, a, b);
    int afb = findfb(a), bfb = findfb(b);  //小数位
    int asb = findfs(a), bsb = findfs(b);  //第一个有效位
    char as[110], bs[110];
    preb(a, as, asb, n), preb(b, bs, bsb, n);
    int aexp = getexp(asb, afb), bexp = getexp(bsb, bfb);
    //不是比较有效位和小数位，而是直接比较指数
    if (aexp != bexp || strcmp(as, bs)) {
        printf("NO 0.%s*10^%d 0.%s*10^%d\n", as, aexp, bs, bexp);
    } else {
        printf("YES 0.%s*10^%d\n", as, aexp);
    }
    return 0;
}