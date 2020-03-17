#include <iostream>
#include <vector>

using namespace std;

struct Move {
    int to, dis, cost;
};

struct Node {
    bool visitd;
    vector<Move> nbs;
} nodes[500];

struct Solution {
    int dis = -1, cost;
    vector<int> cities;
    bool operator<(Solution b) {
        if (dis == b.dis) {
            return cost < b.cost;
        }
        return dis < b.dis;
    }
} best;

int n, m, s, d;

void dfs(int to, Solution sol) {
    if (to == d) {
        if (best.dis == -1 || sol < best) {
            best = sol;
        }
        return;
    }
    for (int i = 0; i < nodes[to].nbs.size(); i++) {
        Move next = nodes[to].nbs[i];
        if (!nodes[next.to].visitd) {
            sol.dis += next.dis, sol.cost += next.cost;
            nodes[next.to].visitd = true;
            sol.cities.push_back(next.to);
            dfs(next.to, sol);
            sol.cities.pop_back();
            nodes[next.to].visitd = false;
            sol.dis -= next.dis, sol.cost -= next.cost;
        }
    }
}

int main() {
    cin >> n >> m >> s >> d;
    for (int i = 0; i < m; i++) {
        Move m;
        int c1, c2;
        scanf("%d %d %d %d", &c1, &c2, &m.dis, &m.cost);
        m.to = c1, nodes[c2].nbs.push_back(m);
        m.to = c2, nodes[c1].nbs.push_back(m);
    }
    Solution sol;
    sol.dis = 0, sol.cost = 0, sol.cities.push_back(s);
    dfs(s, sol);
    for (int i = 0; i < best.cities.size(); i++) {
        printf("%d ", best.cities[i]);
    }
    printf("%d %d\n", best.dis, best.cost);
    return 0;
}