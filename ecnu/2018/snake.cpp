#include <iostream>

using namespace std;
long long snake(int s, int n, int row);
long long snake(int n);
int main(void) {
    snake(20000);
}
long long snake(int n) {
    for (int i = 0; i < n; i++) {
        long long sum = snake(1, n, i + 1);
        // cout << sum << endl;
    }
}
long long snake(int s, int n, int row) {
    long long sum=0;
    if (n <= 0)
        sum= 0;
    if (row == 1) {
        sum= (s + n - 1 + s) * n / 2;
    }
    if (row == n) {
        sum= (s + 2 * n - 2 + s + 3 * n - 3) * n / 2;
    } else
        sum= (2 * s + 5 * n - 5) + snake(s + 4 * n - 4, n - 2, row - 1);
    return sum;
}
