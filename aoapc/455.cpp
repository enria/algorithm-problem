#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string ss[n];
    for (int i = 0; i < n; i++) {
        cin >> ss[i];
    }
    for (int s = 0; s < n; s++) {
        for (int i = 1; i <= ss[s].length(); i++) {
            if (ss[s].length() % i)
                continue;
            bool err = false;
            for (int j = i; j < ss[s].length(); j += i) {
                for (int k = 0; k < i; k++) {
                    if (ss[s][k] != ss[s][j + k]) {
                        err = true;
                        // printf("%d %d %d\n", i, j, k);
                        break;
                    }
                }
                if (err) {
                    break;
                }
            }
            if (!err) {
                cout << i << endl;
                if (s != n - 1)
                    cout << endl;
                break;
            }
        }
    }
    return 0;
}