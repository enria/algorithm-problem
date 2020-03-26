#include <iostream>

using namespace std;

int main() {
    int k, n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        int rs[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", rs + j);
        }
        bool sol = true;
        for (int j = 0; j < n; j++) {
            int r = rs[j];
            for (int k = j + 1; k < n && (r + (k - j)) < n; k++) {  //往上走
                if (rs[k] - r == k - j) {
                    sol = false;
                    break;
                }
            }
            if (sol)
                for (int k = j + 1; k < n && (r - (k - j)) > 0; k++) {  //往下走
                    if (r - rs[k] == k - j) {
                        sol = false;
                        break;
                    }
                }
            if (sol)
                for (int k = j + 1; k < n; k++) {  //往中走
                    if (rs[k] == r) {
                        sol = false;
                        break;
                    }
                }
            if (!sol) {
                break;
            }
        }
        printf(sol ? "YES\n" : "NO\n");
    }
    return 0;
}