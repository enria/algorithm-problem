#include <iostream>
#include <string>

using namespace std;
int out = 0;
void spt(int n, string exp, int m = 1, bool f = false) {
    if (m > n)
        return;
    for (int i = m; i <= n; i++) {
        if (i == n) {
            out++;
            cout << exp + (f ? "" : "+") + to_string(i);
            if (f)
                cout << endl;
            else {
                cout << (out % 4 == 0 ? "\n" : ";");
            }

        } else {
            spt(n - i, exp + (f ? "" : "+") + to_string(i), i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    spt(n, to_string(n) + "=", 1, true);
    return 0;
}