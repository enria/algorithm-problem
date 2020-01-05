#include <iomanip>
#include <iostream>

using namespace std;

double div(int to) {
    double r = 1;
    for (int i = 1; i <= to; i++) {
        r *= i * 1.0 / (2 * i + 1);
    }
    return r;
}

double pi(double a) {
    double pi = 1;
    double item = 1;
    for (int i = 1; item >= a; i++) {
        item = div(i);
        pi += item;
    }
    return pi * 2;
}

int main() {
    double a;
    cin >> a;
    cout << setiosflags(ios::fixed) << setprecision(6) << pi(a);
    return 0;
}