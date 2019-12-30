#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool so = false;
    for (int x = 1; x <= n/2; x++) {
        for (int y = x; y < n; y++) {
            if (x * x + y * y == n) {
                cout << x << " " << y << endl;
                so = true;
            }
        }
    }

    if (!so) {
        cout << "No Solution";
    }
    return 0;
}