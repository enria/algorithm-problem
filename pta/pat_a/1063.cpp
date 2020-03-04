#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

pair<int, int> cnt(set<int> a, set<int> b) {
    int inter = 0;
    auto bit = b.begin();
    for (auto ait = a.begin(); ait != a.end(); ait++) {
        while (bit != b.end() && *bit < *ait) {
            bit++;
        }
        if (bit == b.end()) {
            break;
        } else if (*bit == *ait) {
            inter++;
        }
    }
    return pair<int, int>(inter, (a.size() + b.size() - inter));
}

int main() {
    int n;
    cin >> n;
    set<int> ss[n + 1];
    for (int i = 1, m; i <= n; i++) {
        scanf("%d", &m);
        for (int j = 0, num; j < m; j++) {
            scanf("%d", &num);
            ss[i].insert(num);
        }
    }
    int k;
    cin >> k;
    for (int i = 0, a, b; i < k; i++) {
        set<int> inter;
        scanf("%d %d", &a, &b);

#if (1)  //方法1 居然还比方法2要慢！！！啥情况？气死我了。
        pair<int, int> inter_union = cnt(ss[a], ss[b]);
        printf("%.1f%\n", inter_union.first * 100.0 / inter_union.second);
#endif

#if (0)
        set_intersection(ss[a].begin(), ss[a].end(), ss[b].begin(), ss[b].end(),
                         inserter(inter, inter.begin()));
        printf("%.1f%\n", inter.size() * 100.0 /
                              (ss[a].size() + ss[b].size() - inter.size()));
#endif
    }

    return 0;
}