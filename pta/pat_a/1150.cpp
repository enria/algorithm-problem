#include <iostream>
#include <map>
#include <set>
#include <vector>

#define INF 100000000

using namespace std;

struct Node {
    map<int, int> nbs;
} nodes[201];

string desc_text[] = {"TS simple cycle", "TS cycle", "Not a TS cycle"};

int main() {
    int N, m, k;
    cin >> N >> m;
    for (int i = 0, c1, c2, dist; i < m; i++) {
        scanf("%d %d %d", &c1, &c2, &dist);
        nodes[c1].nbs[c2] = dist;
        nodes[c2].nbs[c1] = dist;
    }
    cin >> k;
    pair<int, int> min_dist = {0, INF};
    for (int i = 0, n; i < k; i++) {
        scanf("%d", &n);
        int path[n];
        set<int> pathn;
        for (int j = 0; j < n; j++) {
            scanf("%d", path + j);
            pathn.insert(path[j]);
        }
        int desc = 0, dist = 0;
        if (n > N + 1) desc = 1;
        if (n < N + 1 || path[0] != path[n - 1] || pathn.size() != N) desc = 2;
        for (int j = 0, move; j < n - 1; j++) {
            move = nodes[path[j]].nbs[path[j + 1]];
            if (move) {
                dist += move;
            } else {
                desc = 2;
                dist = -1;
                break;
            }
        }
        printf("Path %d: ", i + 1);
        cout << (dist > -1 ? to_string(dist) : "NA");
        printf(" (%s)\n", desc_text[desc].c_str());
        if (desc != 2 && dist < min_dist.second) {
            min_dist = {i + 1, dist};
        }
    }
    printf("Shortest Dist(%d) = %d\n", min_dist.first, min_dist.second);
    return 0;
}