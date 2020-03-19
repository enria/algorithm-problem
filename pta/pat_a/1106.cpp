#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    vector<int> cds;
} nodes[100010];

pair<int, int> levelOrder(int root) {
    queue<int> q;
    q.push(root);
    int level = 1, cln = 1, nln = 0, cnt = 0, leaf_cnt = 0;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        if (nodes[cur].cds.size()) {
            for (int i = 0; i < nodes[cur].cds.size(); i++) {
                q.push(nodes[cur].cds[i]);
                nln++;
            }
        } else {
            leaf_cnt++;
        }
        if (++cnt == cln) {
            if (leaf_cnt) {
                return {level, leaf_cnt};
            }
            level++, cln = nln, nln = 0, cnt = 0;
        }
    }
}

int main() {
    int n;
    double p, r;
    cin >> n >> p >> r;
    int cds, cd;
    for (int i = 0; i < n; i++) {
        scanf("%d", &cds);
        for (int j = 0; j < cds; j++) {
            scanf("%d", &cd);
            nodes[i].cds.push_back(cd);
        }
    }
    pair<int, int> level = levelOrder(0);
    printf("%.4lf %d\n", p * pow(1 + r / 100, level.first - 1), level.second);
    return 0;
}