#include <cstring>
#include <iostream>

using namespace std;

bool is_prime(int num) {
    if (num == 1) return 0;
    if (num <= 3) return 1;
    if (num % 6 != 1 && num % 6 != 5) return 0;
    for (int i = 5; i * i <= num; i += 6)
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    return 1;
}

int min_prime(int num) {
    while (!is_prime(num)) {
        num++;
    }
    return num;
}

int main() {
    int m, n;
    cin >> m >> n;
    m = min_prime(m);
    int dat[m];
    int pos[n];
    memset(dat, 0, sizeof(dat));
    for (int i = 0, index, num, col; i < n; i++) {
        scanf("%d", &num);
        index = num % m, col = 0;
        while (col < m / 2) {//平方插入法
            if (dat[index]) {
                col++;
            } else {
                dat[index] = num;
                break;
            }
            index = (num + col * col) % m;
        }
        pos[i] = col < m / 2 ? index : -1;
    }
    for (int i = 0; i < n; i++) {
        if (pos[i] > -1) {
            printf("%d", pos[i]);
        } else {
            printf("-");
        }
        printf(i == n - 1 ? "\n" : " ");
    }
    return 0;
}