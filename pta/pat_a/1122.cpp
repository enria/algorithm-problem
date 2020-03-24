#include <iostream>
#include <map>
using namespace std;

struct Node {
    map<int, int> nbs;
} nodes[201];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        nodes[v1].nbs[v2] = 1;
        nodes[v2].nbs[v1] = 1;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int kn, v;
        scanf("%d", &kn);
        map<int, int> appears;
        int vs[kn];
        bool isH = kn == n+1;
        for (int j = 0; j < kn; j++) {
            scanf("%d", &v);
            appears[v]++, vs[j] = v;
            if (j == kn - 1) {
                if (v != vs[0]) {
                    isH = false;
                }
            } else {
                if (appears[v] >= 2) {
                    isH = false;
                }
            }
        }
        if (isH) {
            for (int i = 0; i < kn - 1; i++) {
                if (!nodes[vs[i]].nbs[vs[i + 1]]) {
                    isH = false;
                    break;
                }
            }
        }
        printf(isH ? "YES\n" : "NO\n");
    }

    return 0;
}