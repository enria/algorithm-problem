#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, vector<int>> dat;
map<int, int> cnt;  //以此元素为根的最大深度
map<int, int> fa;

int cc(int father, int cur) {
    vector<int> chis = dat[cur];
    int max = 1;
    for (int i = 0; i < chis.size(); i++) {
        if (chis[i] != father) {
            int _childc = cc(cur, chis[i]) + 1;
            if (_childc > max) {
                max = _childc;
            }
        } else {
            fa[cur] = i;
        }
    }
    cnt[cur] = max;
    return max;
}
void cc2(int father, int cur) {
    if (father != -1) {
        int father_to_child = cnt[father] + 1;
        if (father_to_child > cnt[cur]) {
            cnt[cur] = father_to_child;
        }
    }
    vector<int> children = dat[cur];
    for (size_t i = 0; i < children.size(); i++) {
        if (children[i] != father) cc2(cur, children[i]);
    }
}

bool is_tree(){
    
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        if (dat.count(a)) {
            dat[a].push_back(b);
        } else {
            vector<int> _v;
            _v.push_back(b);
            dat[a] = _v;
        }

        if (dat.count(b)) {
            dat[b].push_back(a);
        } else {
            vector<int> _v;
            _v.push_back(a);
            dat[b] = _v;
        }
    }
    int max[n];
    for (int i = 1; i <= n; i++) {
        max[i - 1] = cc(-1, i);
    }
    int mi = *(max_element(max, max + n));

    for (int i = 0; i < n; i++) {
        if (max[i] == mi) {
            cout << i + 1 << endl;
        }
    }

    // vector<pair<int, int>> _c(cnt.begin(), cnt.end());
    // sort(_c.begin(), _c.end(), [](pair<int, int> a, pair<int, int> b) -> bool
    // {
    //     if (a.second != b.second) {
    //         return a.second > b.second;
    //     }
    //     return a.first < b.first;
    // });
    // int max = _c[0].second;
    // cout << max << endl;
    // int i = 0;
    // while (_c[i].second == max) {
    //     printf("%d\n", _c[i].first);
    //     i++;
    // }

    return 0;
}