#include <string.h>
#include <iostream>

using namespace std;

int dat[10010];
int ord[10010];

int main() {
    memset(dat, 0, sizeof(int) * 10010);
    memset(ord, 0, sizeof(int) * 10010);
    int n;
    cin >> n;
    while (n--) {
        int _k;
        cin >> _k;
        dat[_k] += 1;
        if (ord[_k] == 0) {
            ord[_k] = n;
        }
    }
    int first = -1, od = -1;
    for (int i = 1; i <= 10000; i++) {
        if (dat[i] == 1) {
            if (ord[i] > od) {
                od = ord[i];
                first = i;
            }
        }
    }
    if (first == -1) {
        cout << "None" << endl;
    } else {
        cout << first << endl;
    }

    return 0;
}