#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

// TODO 使用并查集计算连通分量
// [forget] TODO 使用并查集（树）计算连通分量

using namespace std;

int father[10001];
map<int, vector<int>> conn;
int deepest = 0;

void merge(int a, int b) {
    if (father[a] != father[b]) {  // [通过经验可得，没有影响] TODO a和b的顺序对这个有影响吗？ 
        while (father[b] != b) {
            b = father[b];
        }
        father[b] = father[a];
    }
}

int deep(int root, set<int> &us, int father = 0, int height = 1) {
    if (height > deepest) {
        us.clear();
        deepest = height;
        us.insert(root);
    } else if (height == deepest) {
        us.insert(root);
    }
    int max = 0;
    for (int i = 0; i < conn[root].size(); i++) {
        if (conn[root][i] != father) {
            int _d = deep(conn[root][i], us, root, height + 1);
            if (_d > max) {
                max = _d;
            }
        }
    }
    return max + 1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        merge(a, b);
        conn[a].push_back(b);
        conn[b].push_back(a);
    }
    int groups = 0;
    for (int i = 1; i <= n; i++) {
        if (father[i] == i) {
            groups++;
        }
    }
    if (groups != 1) {
        printf("Error: %d components\n", groups);
    } else {
        set<int> first, second;
        deep(1, first);
        deepest = 0;
        deep(*first.begin(), second);
        first.insert(second.begin(), second.end());
        for (auto i = first.begin(); i != first.end(); i++) {
            printf("%d\n", *i);
        }
    }
    return 0;
}