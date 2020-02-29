#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n13, n2;
    n13 = (s.length() + 2) / 3, n2 = (s.length()) - 2 * n13;
    for (int i = 0; i < n13; i++) {
        cout << s.at(i);
        if (i == n13 - 1) {
            for (int j = n13; j < n13 + n2; j++) {
                cout << s.at(j);
            }

        } else {
            for (int j = 0; j < n2; j++) {
                cout << " ";
            }
        }
        cout << s.at(s.length() - 1 - i)<<endl;
    }
    return 0;
}