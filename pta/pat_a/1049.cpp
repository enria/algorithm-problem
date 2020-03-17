#include <cmath>
#include <iostream>

using namespace std;

int zs1(int n) {  // 10的次方位数中1的个数，n是位数，比如3就是0-999
    if (n <= 0) return 0;
    return 10 * zs1(n - 1) + pow(10, n - 1);
}

int cnt1(int num) {
    if (num == 0) return 0;
    int cnt = 0, ws = (int)log10(num), w1 = num / pow(10, ws);
    cnt += w1 * zs1(ws);
    if (w1 > 1) cnt += pow(10, ws);
    cnt += cnt1(num - w1 * (int)pow(10, ws));
    if (w1 == 1) cnt += num - w1 * pow(10, ws) + 1;
    return cnt;
}

int main() {
    int num;
    cin >> num;
    cout << cnt1(num) << endl;
    return 0;
}