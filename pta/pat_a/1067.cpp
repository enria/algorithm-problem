#include <iostream>
#include <map>

using namespace std;

// TODO: map 添加是红黑树，添加，删除，查找都是lg(n)

int main() {
    int n;
    cin >> n;
    map<int, int> dat;
    for (int i = 0, num; i < n; i++) {
        scanf("%d", &num);
        if (num != i || num == 0) {
            dat[num] = i;
        }
    }

    int change_times = 0, pos;
    while (dat.size() > 1) {
        if (dat[0] != 0) {
            pos = dat[dat[0]];
            dat.erase(dat[0]);
            dat[0] = pos;
        } else {
            auto it = ++dat.begin();
            dat[0] = it->second;
            dat[it->first] = 0;
        }
        change_times++;
    }
    cout << change_times << endl;
    return 0;
}