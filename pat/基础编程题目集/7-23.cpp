#include <iostream>

using namespace std;

string qw(int num, bool z = true) {
    int q[] = {num / 1000, num / 100 % 10, num / 10 % 10, num % 10};
    string result = "";
    char wl[] = {'Q', 'B', 'S', 0};
    for (int i = 0; i < 4; i++) {
        if (q[i] == 0) {
            if (z) {
                result = result + char('a');
            }
            z = false;
        } else {
            result = result + char(q[i] + 'a') + wl[i];
            z = true;
        }
    }
    for (int i = result.length() - 1; i >= 0; i--) {
        if (result.at(i) == 'a' || result.at(i) == 0) {
            result.replace(i, 1, "");
        } else {
            break;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    int we[] = {10000 * 10000, 10000, 1};
    char w[] = {'Y', 'W', 0};
    string result = "";
    bool z = false;
    for (int i = 0; i < 3; i++) {
        int q = n / we[i];
        n = n - q * we[i];
        if (q != 0) {
            result = result + qw(q, result.length()!=0) + w[i];
            z = true;
        } else {
            if (z) {
                result = result + 'a';
            }
        }
    }
    if (result.length() == 0)
        result = "a";
    cout << result;
}