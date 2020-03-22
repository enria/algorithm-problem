#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int left = -1, right = -1;
} nodes[20];

pair<bool, int> level(int root) {
    queue<int> q;
    q.push(root);
    int level = 0, cln = 1, nln = 0, cnt = 0;
    vector<int> pren, curn;
    while (q.size()) {
        int cur = q.front();
        if (nodes[cur].left == -1 && nodes[cur].right != -1)
            return {false, root};
        if (nodes[cur].left != -1) {
            q.push(nodes[cur].left);
            nln++;
        }
        if (nodes[cur].right != -1) {
            q.push(nodes[cur].right);
            nln++;
        }
        q.pop();
        curn.push_back(cur);
        if (++cnt == cln) {
            if (cnt != pow(2, level)) {
                if (q.size()) {  //如果当前层不填满，而且不是最后一层的话，不是完全二叉树
                    return {false, root};
                } else {  //如果最底层不是上层从左到右的孩子的话，也不是完全二叉树
                    for (int i = 0; i < curn.size(); i++) {
                        Node parent = nodes[pren[i / 2]];
                        if ((i % 2 == 1 && curn[i] != parent.right) ||
                            (i % 2 == 0 && curn[i] != parent.left)) {
                            return {false, root};
                        }
                    }
                }
            }
            pren = curn, curn.clear();
            cnt = 0, cln = nln, nln = 0;
            level++;
        }
    }
    return {true, pren[pren.size() - 1]};
}

int main() {
    int N;
    cin >> N;
    char c1[3], c2[3];
    bool isRoot[N];
    fill(isRoot, isRoot + N, true);
    for (int i = 0; i < N; i++) {
        scanf("%s %s", c1, c2);
        if (c1[0] != '-') {
            nodes[i].left = stoi(c1);
            isRoot[stoi(c1)] = false;
        }
        if (c2[0] != '-') {
            nodes[i].right = stoi(c2);
            isRoot[stoi(c2)] = false;
        }
    }
    int root;
    for (int i = 0; i < N; i++) {
        if (isRoot[i]) {
            root = i;
            break;
        }
    }
    pair<bool, int> result = level(root);
    printf(result.first ? "YES" : "NO");
    printf(" %d\n", result.second);
    return 0;
}