#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
int c, n, sp, m;
struct Node {
    int cur = 0;
    bool visited = false;
    vector<pair<int, int>> nbs;  //{id，time}
} nodes[510];

struct Solution {
    int need = -1, cur = 0, cost = 0;  // TODO 这里的初值是什么？
    vector<int> sts;
    bool operator<(Solution a) {
        if (cost == a.cost) {
            if (need == a.need) {
                return cur < a.cur;
            }
            return need < a.need;
        }
        return cost < a.cost;
    }
} best;

void dfs(int to, Solution sol) {
    if (to == sp) {
        if (best.need == -1 || sol < best) {
            best = sol;
        }
        return;
    }
    for (int i = 0; i < nodes[to].nbs.size(); i++) {
        pair<int, int> move = nodes[to].nbs[i];
        if (!nodes[move.first].visited) {
            Solution newSol = sol;
            newSol.cost += move.second;
            nodes[move.first].visited = true;
            Node next = nodes[move.first];
            if (next.cur > c / 2) {
                newSol.cur += next.cur - c / 2;
            } else if (next.cur < c / 2) {
                if (newSol.cur < c / 2 - next.cur) {
                    newSol.need += c / 2 - next.cur - newSol.cur;
                    newSol.cur = 0;
                } else {
                    newSol.cur -= c / 2 - next.cur;
                }
            }
            if (best.need > -1 && best < newSol) {
                nodes[move.first].visited = false;  //注意恢复现场
                continue;
            }
            newSol.sts.push_back(move.first);
            dfs(move.first, newSol);
            nodes[move.first].visited = false;
        }
    }
}

int main() {
    cin >> c >> n >> sp >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nodes[i].cur);
    }
    int s1, s2, cost;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &s1, &s2, &cost);
        nodes[s1].nbs.push_back({s2, cost});
        nodes[s2].nbs.push_back({s1, cost});
    }
    Solution sol;
    sol.need = 0, sol.sts.push_back(0), nodes[0].visited = true;
    dfs(0, sol);
    printf("%d ", best.need);
    for (int i = 0; i < best.sts.size(); i++) {
        printf("%d", best.sts[i]);
        printf(i == best.sts.size() - 1 ? " " : "->");
    }
    printf("%d\n", best.cur);
    return 0;
}