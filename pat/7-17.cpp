#include <math.h>
#include <iostream>

using namespace std;

int main() {
    int n, u, d;
    scanf("%d %d %d", &n, &u, &d);
    int m = 1;
    n = n - u;
    int ym = 0;
    if (n > 0) {
        ym = ceill(n*1.0 / (u - d))*2;
    }
    cout << ym + m;
    return 0;
}