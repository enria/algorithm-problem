#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int left = -1, right = -1;
} nodes[10];

void invert(int root) {
    if (root == -1) return;
    // 1：先换子孙，再换儿子；2：先换儿子，再换子孙。
    int temp = nodes[root].left;
    nodes[root].left = nodes[root].right;
    nodes[root].right = temp;
    invert(nodes[root].left);
    invert(nodes[root].right);
}

vector<int> levelOrder, inOrder;

void level(int root) {
    queue<int> q;
    q.push(root);
    while (q.size()) {
        int cur = q.front();
        if (nodes[cur].left > -1) q.push(nodes[cur].left);
        if (nodes[cur].right > -1) q.push(nodes[cur].right);
        q.pop();
        levelOrder.push_back(cur);
    }
}

void in(int root) {
    if (root == -1) return;
    in(nodes[root].left);
    inOrder.push_back(root);
    in(nodes[root].right);
}

int main() {
    int n;
    scanf("%d", &n);
    bool isChd[n];
    fill(isChd, isChd + n, false);
    for (int i = 0; i < n; i++) {
        char c1, c2;
        scanf("\n%c %c", &c1, &c2);
        if (c1 != '-') {
            nodes[i].left = c1 - '0';
            isChd[c1 - '0'] = true;
        }
        if (c2 != '-') {
            nodes[i].right = c2 - '0';
            isChd[c2 - '0'] = true;
        }
    }
    int root;
    for (int i = 0; i < n; i++) {
        if (!isChd[i]) {
            root = i;
            break;
        }
    }
    invert(root);
    level(root), in(root);
    for (int i = 0; i < levelOrder.size(); i++) {
        printf("%d", levelOrder[i]);
        printf(i == levelOrder.size() - 1 ? "\n" : " ");
    }
    for (int i = 0; i < inOrder.size(); i++) {
        printf("%d", inOrder[i]);
        printf(i == inOrder.size() - 1 ? "\n" : " ");
    }

    return 0;
}