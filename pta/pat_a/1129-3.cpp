#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
struct Node {
    int id, cnt;
    Node(int a, int b) : id(a), cnt(b) {}
    bool operator<(const Node b) const {
        if (cnt == b.cnt) {
            return id < b.id;
        }
        return cnt > b.cnt;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    set<Node> items;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int id, j = 0;
        scanf("%d", &id);
        vector<int> rs;
        for (auto it = items.begin(); it != items.end() && j < k; it++, j++) {
            rs.push_back(it->id);
        }
        if (rs.size()) {
            printf("%d:", id);
            for (j = 0; j < rs.size(); j++) {
                printf(" %d", rs[j]);
            }
            printf("\n");
        }
        if (cnt[id]) {
            items.erase(Node(id, cnt[id]));
        }
        items.insert(Node(id, ++cnt[id]));
    }
    return 0;
}