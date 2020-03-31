#include <iostream>
#include <set>
using namespace std;
bool nbs_matrix[201][201];

bool isNb(int cur, set<int>::iterator nodes, set<int>::iterator nodee) {
    for (auto it = nodes; it != nodee; it++) {
        if (*it != cur && !nbs_matrix[cur][*it]) {
            return false;
        }
    }
    return true;
}

int main() {
    int nv, ne;
    cin >> nv >> ne;
    for (int i = 0; i < ne; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        nbs_matrix[v1][v2] = nbs_matrix[v2][v1] = true;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        set<int> ori;
        for (int i = 0; i < k; i++) {
            int v;
            scanf("%d", &v);
            ori.insert(v);
        }
        bool isClique = true;
        for (auto it = ori.begin(); it != ori.end(); it++) {
            /*只看后面的，因为是无向的，已经被前面的看过了*/
            if (!isNb(*it, it, ori.end())) {
                isClique = false;
                break;
            }
        }
        if (!isClique) {
            printf("Not a Clique\n");
            continue;
        }
        set<int> nbs;
        auto fir = ori.begin();
        for (int j = 1; j <= nv; j++) {
            if (nbs_matrix[j][*fir] && ori.find(j) == ori.end()) {
                nbs.insert(j);
            }
        }
        bool isMax = true;
        for (auto it = nbs.begin(); it != nbs.end(); it++) {
            if (isNb(*it, ori.begin(), ori.end())) {
                isMax = false;
                break;
            }
        }
        printf(isMax ? "Yes\n" : "Not Maximal\n");
    }

    return 0;
}