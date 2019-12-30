#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ns[] = {n, n + 1, n + 2, n + 3};
    for (int i1 = 0; i1 < 4; i1++) {
        int i = 0;
        for (int i2 = 0; i2 < 4; i2++) {
            for (int i3 = 0; i3 < 4; i3++) {
                if (i1 != i2 && i1 != i3 && i2 != i3) {
                    printf("%d%d%d", ns[i1], ns[i2], ns[i3]);
                    if (++i < 6) {
                        printf(" ");
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}