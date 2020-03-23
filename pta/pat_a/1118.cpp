#include <iostream>
#include <map>

using namespace std;

map<int, int> roots;

int findRoot(int id) {
    if (roots[id] == 0) roots[id] = id;
    if (roots[id] == id) return id;
    return roots[id] = findRoot(roots[id]);  //缩短路径
}

int main() {
    int n, k, q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        int root, id;
        for (int j = 0; j < k; j++) {
            scanf("%d", &id);
            if (j == 0) {
                root = findRoot(id);
            } else {
                roots[findRoot(id)] = root;  //喜结连理
            }
        }
    }
    int tree = 0;
    for (auto it = roots.begin(); it != roots.end(); it++) {
        if (it->first == it->second) {
            tree++;
        }
    }
    printf("%d %lu\n", tree, roots.size());
    cin >> q;
    for (int i = 0; i < q; i++) {
        int b1, b2;
        scanf("%d %d", &b1, &b2);
        printf(findRoot(b1) == findRoot(b2) ? "Yes\n" : "No\n");
    }
    return 0;
}