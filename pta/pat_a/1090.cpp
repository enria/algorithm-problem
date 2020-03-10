#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    vector<int> child;
} nodes[100010];

vector<int> maxmember;
int maxlevel = 0;

void dfs(int root, int level) {  // level当前层级
    if (nodes[root].child.size()) {
        for (int i = 0; i < nodes[root].child.size(); i++) {
            dfs(nodes[root].child[i], level + 1);
        }
    } else {
        if (level > maxlevel) {
            maxmember.clear();
            maxmember.push_back(root);
            maxlevel = level;
        } else if (level == maxlevel) {
            maxmember.push_back(root);
        }
    }
}

int main() {
    int n, root;
    double p, r;//float居然就出错了，真是搞不懂
    cin >> n >> p >> r;
    for (int i = 0, sup; i < n; i++) {
        scanf("%d", &sup);
        if (sup == -1) {
            root = i;
        } else {
            nodes[sup].child.push_back(i);
        }
    }
    dfs(root, 1);
    printf("%.2f %d\n", p * (pow(1 + r / 100, maxlevel - 1)), maxmember.size());
    return 0;
}