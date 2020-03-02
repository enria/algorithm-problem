#include <string.h>
#include <iostream>

using namespace std;

int coins[501];

int main() {
    memset(coins, 0, sizeof(coins));
    int n, m;
    cin >> n >> m;
    int _c;
    for (int i = 0; i < n; i++) {
        scanf("%d", &_c);
        coins[_c] += 1;
    }
    pair<int, int> so(0, 0);
    for (int i = 1; i <= 500 && i * 2 <= m; i++) {
        if (!coins[i]) continue;
        if (2 * i == m) {
            if (coins[i] >= 2) {
                so.first = so.second = i;
            }
            break;
        }
        if (m - i <= 500 && coins[m - i]) {
            so.first = i;
            so.second = m - i;
            break;
        }
    }
    if (!so.first) {
        printf("No Solution\n");
    } else {
        printf("%d %d\n", so.first, so.second);
    }

    return 0;
}