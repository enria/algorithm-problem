#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int no[n];
    for (int i = 0; i < n; i++) {
        no[i] = 1;
    }
    int h = 0;
    int s = n, l;
    while (s > 0) {
        s = 0;
        for (int i = 0; i < n; i++) {
            if (no[i]) {
                s++;
                if (++h == 3) {
                    no[i] = 0;
                    h = 0;
                } else {
                    l = i + 1;
                }
            }
        }
    }
    cout << l;
    return 0;
}