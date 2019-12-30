#include <math.h>
#include <iostream>

using namespace std;
#define TW "@_@"
#define RW "^_^"
#define BW "-_-"

int main() {
    int m;
    cin >> m;
    int loop = m / 90;
    int c = m % 90;
    if (c == 0 || c == 30 || c == 45 || c == 55) {
        cout << BW << " ";
        cout << 3 * m;
    } else if (c < 30) {
        cout << RW << " ";
        cout << loop * 270 + min(m * 9, 90);
    } else if (c < 45) {
        cout << TW << " ";
        cout << 3 * m;
    } else if (c < 55) {
        cout << RW << " ";
        cout << loop * 270 + 90 + min((m - 40) * 9, 90);
    } else {
        cout << TW << " ";
        cout << 3 * m;
    }
    return 0;
}