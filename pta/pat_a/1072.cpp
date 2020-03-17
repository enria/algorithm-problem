#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    vector<pair<int, int>> nbs;
} points[1020];

int n, m, k, d;

int MAX = 0x3ffffff;

pair<int, double> comput(int gas) {
    int dis[1020];
    fill(dis, dis + 1020, MAX), dis[gas] = 0;  //初值不为0
    map<int, int> choose;
    choose[gas] = 0;
    int cur_choose = gas;
    while (cur_choose != -1) {
        dis[cur_choose] = choose[cur_choose];
        if (choose[cur_choose] > d) {
            return pair<int, double>(-1, 0.0);
        }
        for (int i = 0; i < points[cur_choose].nbs.size(); i++) {
            pair<int, int> nb = points[cur_choose].nbs[i];
            if (!choose[nb.first]) {  //没有值
                choose[nb.first] = dis[cur_choose] + nb.second;
            } else if (dis[cur_choose] + nb.second < choose[nb.first]) {
                choose[nb.first] = dis[cur_choose] + nb.second;
            }
        }
        pair<int, int> minx(-1, 0);  //前面是序号，后面是距离
        for (auto it = choose.begin(); it != choose.end(); it++) {
            if (dis[it->first] == MAX) {
                if (minx.first == -1 || it->second < minx.second) {
                    minx = *it;
                }
            }
        }
        cur_choose = minx.first;
    }
    int minx;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == 1 || minx > dis[i]) minx = dis[i];
        if (dis[i] == -1) return pair<int, double>(-1, 0.0);
        sum += dis[i];
    }
    return pair<int, double>(minx, sum * 1.0 / n);
}

const int maxn = 1011;

pair<int, double> Dijistra(int s) {
    int vis[maxn], dis[maxn];
    memset(vis, 0, sizeof(vis));
    fill(dis, dis + maxn, 0x3f3f3f3f);
    dis[s] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        vis[u] = 1;
        for (int i = 0; i < points[u].nbs.size(); ++i) {
            int v = points[u].nbs[i].first, w = points[u].nbs[i].second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (vis[v] == 0) q.push({-dis[v], v});
            }
        }
    }
    int minx;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == 1 || minx > dis[i]) minx = dis[i];
        if (dis[i] == -1 || dis[i] > d) return pair<int, double>(-1, 0.0);
        sum += dis[i];
    }
    return pair<int, double>(minx, sum * 1.0 / n);
}
int main() {
    cin >> n >> m >> k >> d;
    char ps1[5], ps2[5];
    for (int i = 0, dis, p1, p2; i < k; i++) {
        scanf("%s %s %d", ps1, ps2, &dis);
        p1 = ps1[0] == 'G' ? stoi(ps1 + 1) + 1000 : stoi(ps1);
        p2 = ps2[0] == 'G' ? stoi(ps2 + 1) + 1000 : stoi(ps2);
        points[p1].nbs.push_back(pair<int, int>(p2, dis));
        points[p2].nbs.push_back(pair<int, int>(p1, dis));
    }

    pair<int, double> sol(-1, 0.0);
    int choose = -1;
    for (int i = 1; i <= m; i++) {
        pair<int, double> cur_sol = Dijistra(i + 1000);
        if (cur_sol.first > -1) {
            if (choose == -1 || cur_sol.first > sol.first ||
                (cur_sol.first == sol.first &&
                 cur_sol.second < sol.second)) {  // SECOND!!!!!
                sol = cur_sol;
                choose = i;
            }
        }
    }
    if (choose == -1) {
        printf("No Solution\n");
    } else {
        printf("G%d\n%.1f %.1f\n", choose, sol.first * 1.0, sol.second);
    }
    return 0;
}