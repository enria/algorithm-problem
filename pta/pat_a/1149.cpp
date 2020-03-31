#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, set<int>> inps;
    for (int i = 0, g1, g2; i < n; i++) {
        scanf("%d %d", &g1, &g2);
        inps[g1].insert(g2), inps[g2].insert(g1);
    }
    for (int i = 0, k; i < m; i++) {
        scanf("%d", &k);
        set<int> gl;
        for (int j = 0, g; j < k; j++) {
            scanf("%d", &g);
            gl.insert(g);
        }
        int valid = true;
        for (auto it = gl.begin(); it != gl.end(); it++) {
            set<int> ins;
            set_intersection(gl.begin(), gl.end(), inps[*it].begin(),
                             inps[*it].end(), inserter(ins, ins.begin()));
            if (!ins.empty()) {
                valid = false;
                break;
            }
        }
        printf(valid ? "Yes\n" : "No\n");
    }

    return 0;
}
