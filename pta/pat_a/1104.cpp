#include <iostream>

using namespace std;

int main() {
    long n;
    cin >> n;
    double nsum, cur;
    for (long i = 0; i < n; i++) {
        scanf("%lf", &cur);
        nsum += (i * (n - i) + (n - i)) * cur;  //相乘和相加要考虑溢出
    }
    printf("%.2lf\n", nsum);
    return 0;
}