#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Node {
    int color;
    set<int> nbs;
} nodes[10000];

vector<int> colors;
int color_count() {
    for (int i = 0; i < colors.size(); i++) {
        for (auto it = nodes[i].nbs.begin();
             it != nodes[i].nbs.end() && *it < i; it++) {
            if (colors[*it] == colors[i]) {
                return 0;
            }
        }
    }
    return set<int>(colors.begin(), colors.end()).size();
}

int main() {
    int n, m, k;
    cin >> n >> m;
    colors.resize(n);
    for (int i = 0, v1, v2; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        nodes[v1].nbs.insert(v2), nodes[v2].nbs.insert(v1);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &colors[j]);
        }
        int cn = color_count();
        if (cn) {
            printf("%d-coloring\n", cn);
        } else {
            printf("No\n");
        }
    }
    return 0;
}