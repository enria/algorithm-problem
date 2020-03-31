#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Node {
    set<int> pre, next;
};

int main() {
    int n, m, k;
    cin >> n >> m;
    vector<Node> nodes(n + 1);
    for (int i = 0, v1, v2; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        nodes[v1].next.insert(v2);
        nodes[v2].pre.insert(v1);
    }
    cin >> k;
    vector<int> wrong;
    for (int i = 0; i < k; i++) {
        bool top_ord = true;
        vector<Node> temp = nodes;
        for (int j = 0, v; j < n; j++) {
            scanf("%d", &v);
            if (!top_ord) continue;
            if (temp[v].pre.size()) {
                top_ord = false;
                continue;
            }
            for (auto it = temp[v].next.begin(); it != temp[v].next.end(); it++)
                temp[*it].pre.erase(v);
        }
        if (!top_ord) wrong.push_back(i);
    }
    for (int i = 0; i < wrong.size(); i++) {
        printf("%d", wrong[i]);
        printf(i == wrong.size() - 1 ? "\n" : " ");
    }
    return 0;
}