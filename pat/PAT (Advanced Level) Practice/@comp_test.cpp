#include <iostream>

using namespace std;

struct rcd {
    int h, m, s;
};

bool comp1(rcd a, rcd b) {
    if (a.h < b.h) {
        return true;
    } else if (a.h == b.h && a.m < b.m) {
        return true;
    } else if (a.h == b.h && a.m == b.m && a.s < b.s) {
        return true;
    }
    return false;
}

bool comp2(rcd a, rcd b) {
    if (a.h == b.h) {
        if (a.m == b.m)
            return a.s < b.s;
        else
            return a.m < b.m;
    } else {
        return a.h < b.h;
    }
}

int main() {
    int ss[][2] = {{0, 1}, {0, 0}, {1, 0}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                rcd a, b;
                a.h = ss[i][0];
                a.h = ss[i][1];
                a.m = ss[j][0];
                a.m = ss[j][1];
                a.s = ss[k][0];
                a.s = ss[k][1];

                if(comp1(a,b)==comp2(a,b)){
                    cout<<"error"<<endl;
                }
            }
        }
    }

    return 0;
}