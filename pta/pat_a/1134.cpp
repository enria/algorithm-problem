#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Node {
    vector<int> nbs;
} nodes[10000];

int main() {
    set<pair<int, int>> edgs;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        nodes[v1].nbs.push_back(v2);
        nodes[v2].nbs.push_back(v1);
        edgs.insert({min(v1, v2), max(v1, v2)});
    }
    int k, nv, v, nb;
    cin >> k;
    for (int i = 0; i < k; i++) {
        set<pair<int, int>> temp = edgs;
        scanf("%d", &nv);
        for (int j = 0; j < nv; j++) {
            scanf("%d", &v);
            for (int l = 0; l < nodes[v].nbs.size(); l++) {
                nb = nodes[v].nbs[l];
                temp.erase({min(v, nb), max(v, nb)});
            }
        }
        printf(temp.empty() ? "Yes\n" : "No\n");
    }
    return 0;
}