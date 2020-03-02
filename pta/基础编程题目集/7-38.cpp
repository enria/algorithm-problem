#include <ctime>
#include <iostream>
using namespace std;

int main() {
    int a, n;
    cin >> a;
    cin >> n;
    char result[n + 1];
    int jw = 0, wz;
    result[n] = 0;
    for (int i = n; i > 0; i--) {
        wz = a * i + jw;
        result[i - 1] = wz % 10 + '0';
        jw = wz / 10;
    }
    if (jw != 0) {
        cout << jw;
    }
    if (n == 0) {
        cout << jw;
    }
    cout << result << endl;
    return 0;
}