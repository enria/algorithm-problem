#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define pii pair<int, int>

int main() {
    int n, m;
    cin >> n >> m;
    n = n * m;
    map<int, int> cnt;
    while (n--) {
        scanf("%d", &m);
        if (cnt.count(m)) {
            cnt[m] += 1;
        } else {
            cnt[m] = 1;
        }
    }
    // map按value排序
    vector<pair<int, int>> cntv(cnt.begin(), cnt.end());
    int max=max_element(cntv.begin(), cntv.end(),
                [](pii a, pii b) -> bool { return a.second < b.second; })
        ->first;
    cout << max << endl;
    return 0;
}