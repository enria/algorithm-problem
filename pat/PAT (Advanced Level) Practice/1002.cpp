// A+B for Polynomials
#include <iostream>
using namespace std;

#define NK 1001
int main() {
    int ak, bk;
    cin >> ak;
    float ap[NK];
    for (int i = 0; i < ak; i++) {
        int nk;
        cin >> nk;
        cin >> ap[nk];
    }
    cin >> bk;
    float bp[NK];
    for (int i = 0; i < bk; i++) {
        int nk;
        cin >> nk;
        cin >> bp[nk];
    }

    float cp[NK], ct = 0;
    for (int i = 0; i < NK; i++) {
        cp[i] = ap[i] + bp[i];
        if (cp[i] != 0)
            ct++;
    }
    cout << ct;
    for (int i = NK - 1; i >= 0; i--) {
        if (cp[i] != 0) {
            printf(" %d %.1f", i, cp[i]);
        }
    }
    cout<<endl;
    return 0;
}