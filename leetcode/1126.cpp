#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    bool visited = false;
    vector<int> nbs;
} nodes[501];

int bfs(int root) {
    queue<int> q;
    q.push(root), nodes[root].visited = true;
    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop(), cnt++;
        for (int i = 0; i < nodes[cur].nbs.size(); i++) {
            int cd = nodes[cur].nbs[i];
            if (!nodes[cd].visited) {
                q.push(cd), nodes[cd].visited = true;
            }
        }
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        nodes[v1].nbs.push_back(v2);
        nodes[v2].nbs.push_back(v1);
    }
    int odds = 0;
    for (int i = 1; i <= n; i++) {
        printf("%lu", nodes[i].nbs.size());
        printf(i == n ? "\n" : " ");
        if (nodes[i].nbs.size() % 2) odds++;
    }
    int sincircle = bfs(1);
    if (sincircle == n) {
        switch (odds) {
            case 0:
                printf("Eulerian\n");
                break;
            case 2:
                printf("Semi-Eulerian\n");
                break;
            default:
                printf("Non-Eulerian\n");
                break;
        }
    } else {
        printf("Non-Eulerian\n");
    }
    return 0;
}