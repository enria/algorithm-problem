#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int hands;
    bool visited = false;
    vector<pair<int, int>> nbs;
} nodes[500];

int n, m, c1, c2;

struct Solution {
    int path = -1, hands = 0;
    int cnt = 1;
} best;
void dfs(int to, Solution sol) {
    if (to == c2) {
        if (best.path == -1 || best.path > sol.path) {
            best = sol;
        } else if (best.path == sol.path) {
            best.cnt++;
            if (sol.hands > best.hands) {
                best.hands = sol.hands;
            }
        }
        return;
    }
    for (int i = 0; i < nodes[to].nbs.size(); i++) {
        pair<int, int> move = nodes[to].nbs[i];
        if (!nodes[move.first].visited) {
            Solution newSol = sol;  //新建变量，传下去，省得去恢复原状
            newSol.path += move.second, newSol.hands += nodes[move.first].hands;
            if (best.path != -1 && best.path < newSol.path) continue;
            nodes[move.first].visited = true;
            dfs(move.first, newSol);
            nodes[move.first].visited = false;
        }
    }
}

int main() {
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nodes[i].hands);
    }
    for (int i = 0; i < m; i++) {
        int _c1, _c2, path;
        scanf("%d %d %d", &_c1, &_c2, &path);
        nodes[_c1].nbs.push_back({_c2, path});
        nodes[_c2].nbs.push_back({_c1, path});
    }
    Solution sol;
    sol.path = 0, sol.hands = nodes[c1].hands;
    dfs(c1, sol);
    printf("%d %d\n", best.cnt, best.hands);
    return 0;
}