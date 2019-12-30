#include <iomanip>
#include <iostream>

using namespace std;

double fee(double x) {
    if (x <= 15) {
        return 4 * x / 3;
    } else {
        return 2.5 * x - 17.5;
    }
}

int main() {
    double x;
    cin >> x;
    cout << setiosflags(ios::fixed) << setprecision(2) << fee(x);
    return 0;
}