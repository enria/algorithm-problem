#include <cmath>
#include <iostream>

using namespace std;

#define ll long long

ll to_dec(string n, int r) {
    ll result = 0;
    for (int i = n.length() - 1; i >= 0; i--) {
        char c = n.at(i);
        int cur = c <= '9' ? c - '0' : c - 'a' + 10;
        if (cur >= r) {
            throw 0;
        }
        result += cur * pow(r, n.length() - 1 - i);
    }
    return result;
}

int main() {
    string n1, n2;
    int tag, redix;
    cin >> n1 >> n2 >> tag >> redix;
    ll target;
    string s_num;
    int s_redix = 0;
    if (tag == 1) {
        target = to_dec(n1, redix);
        s_num = n2;
    } else {
        target = to_dec(n2, redix);
        s_num = n1;
    }
    for (int i = 2; i <= 36; i++) {
        try {
            if (to_dec(s_num, i) == target) {
                s_redix = i;
                break;
            }
        } catch (int) {
        }
    }
    if (s_redix) {
        cout << s_redix << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}