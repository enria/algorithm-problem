#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    string ss[n];
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, ss[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ss[j] > ss[j + 1]) {
                string temp = ss[j];
                ss[j] = ss[j + 1];
                ss[j + 1] = temp;
            }
        }
        if (i + 1 == k) {
            for (int k = 0; k < n; k++) {
                cout << ss[k] << endl;
            }
            return 0;
        }
    }
}