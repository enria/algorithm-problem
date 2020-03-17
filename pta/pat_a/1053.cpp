#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct Node {
    int w;
    vector<int> cds;
} nodes[100];
int N, M, S;

vector<vector<int>> result;
vector<int> temp;

void find(int nid, int value) {
    if (value > S) {
        return;
    }
    temp.push_back(nodes[nid].w);
    if (nodes[nid].cds.size() == 0) {
        if (value + nodes[nid].w == S) {
            result.push_back(temp);
        }
    } else {
        for (int i = 0; i < nodes[nid].cds.size(); i++) {
            find(nodes[nid].cds[i], value + nodes[nid].w);
        }
    }
    temp.pop_back();
}

bool cmp(vector<int> a, vector<int> b) {
    for (int i = 0; i < a.size() && i < b.size(); ++i) {
        if (a[i] != b[i]) {
            return a[i] > b[i];
        }
    }
    return false;
}

int main() {
    cin >> N >> M >> S;
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &nodes[i].w);
    }
    int id, k, cid;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &cid);
            nodes[id].cds.push_back(cid);
        }
        //还不能用这个方法，可能会出现父结点相同，子结点较小，结果排在后面的情况
        // sort(nodes[i].cds.begin(), nodes[i].cds.end(),
        //      [](int a, int b) -> bool { return nodes[a].w > nodes[b].w; });
    }
    find(0, 0);
    sort(result.begin(), result.end(), cmp);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            printf("%d", result[i][j]);
            printf(j == result[i].size() - 1 ? "\n" : " ");
        }
    }

    return 0;
}