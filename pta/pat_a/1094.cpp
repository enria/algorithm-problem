#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Member {
    vector<int> child;
} members[100];

int largest = 1, gen = 1;

void bfs(int root) {
    queue<int> q;
    q.push(root);
    int cnt = 0, cur = 1, next = 0, cur_gen = 1;
    int first;
    while (q.size()) {
        first = q.front();
        for (int i = 0; i < members[first].child.size(); i++) {
            q.push(members[first].child[i]);
        }
        next += members[first].child.size();
        q.pop();
        if (++cnt == cur) {
            if (cur > largest) {
                largest = cur;
                gen = cur_gen;
            }
            cnt = 0;
            cur = next;
            next = 0;
            cur_gen++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0, mem, k, chi; i < m; i++) {
        scanf("%d %d", &mem, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &chi);
            members[mem].child.push_back(chi);
        }
    }
    bfs(1);
    printf("%d %d\n", largest, gen);
    return 0;
}