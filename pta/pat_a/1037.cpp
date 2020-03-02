#include <algorithm>
#include <iostream>

//TODO 等一个证明

using namespace std;

int main() {
    int nc, np;
    cin >> nc;
    int cs[nc];
    for (int i = 0; i < nc; i++) {
        scanf("%d", cs + i);
    }

    cin >> np;
    int ps[np];
    for (int i = 0; i < np; i++) {
        scanf("%d", ps + i);
    }

    sort(cs, cs + nc), sort(ps, ps + np);

    int earn = 0, cindex = 0;
    for (int i = 0; ps[i] < 0; i++) {
        if (cs[cindex] < 0) {
            earn += ps[i] * cs[cindex++];
        } else {
            break;
        }
    }
    cindex = nc - 1;
    for (int i = np - 1; ps[i] > 0; i--) {
        if (cs[cindex] > 0) {
            earn += ps[i] * cs[cindex--];
        } else {
            break;
        }
    }
    cout << earn << endl;
    return 0;
}