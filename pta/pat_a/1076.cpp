#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct User {
    int id;
    vector<int> followed;
    bool visited;
} users[1001];

int l;
int bfs(int root) {
    users[root].visited = true;
    queue<int> q;
    q.push(root);
    int fans_level = 0, cur_fans = 1, next_fans = 0;
    vector<int> visited;
    while (q.size() && fans_level < l) {
        int cur = q.front();
        for (int i = 0; i < users[cur].followed.size(); i++) {
            if (!users[users[cur].followed[i]].visited) {
                users[users[cur].followed[i]].visited = true;
                visited.push_back(users[cur].followed[i]);
                q.push(users[cur].followed[i]);
                next_fans++;
            }
        }
        cur_fans--;
        if (cur_fans == 0) {
            fans_level++;
            cur_fans = next_fans;
            next_fans = 0;
        }
        q.pop();
    }
    for (int i = 0; i < visited.size(); i++) {
        users[visited[i]].visited = false;
    }
    users[root].visited = false;
    return visited.size();
}

int main() {
    int n, k;
    cin >> n >> l;
    for (int i = 1, fc; i <= n; i++) {
        scanf("%d", &fc);
        for (int j = 0, ui; j < fc; j++) {
            scanf("%d", &ui);
            users[ui].followed.push_back(i);
        }
    }
    cin >> k;
    for (int i = 0, ui; i < k; i++) {
        scanf("%d", &ui);
        printf("%d\n", bfs(ui));
    }
    return 0;
}