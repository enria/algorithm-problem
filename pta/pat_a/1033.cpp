#include <algorithm>
#include <iostream>

// TODO 动态规划
using namespace std;
struct Station {
    float price;
    int tohz;
};

Station sts[505];

int main() {
    int c_max, d, d_avg, n;
    cin >> c_max >> d >> d_avg >> n;
    int bt_max = c_max * d_avg;

    for (int i = 0; i < n; i++) {
        scanf("%f %d", &sts[i].price, &sts[i].tohz);
    }
    sort(sts, sts + n,
         [](Station a, Station b) -> bool { return a.tohz < b.tohz; });

    sts[n].tohz = d;
    float dis_max = d;
    if (sts[0].tohz != 0) {
        dis_max = 0;
    } else {
        for (int i = 0; i <= n; i++) {
            if (sts[i + 1].tohz - sts[i].tohz > bt_max) {
                dis_max = sts[i].tohz + bt_max;
            }
        }
    }

    if (dis_max < d) {
        printf("The maximum travel distance = %.2f\n", dis_max);
    } else {
    }

    return 0;
}