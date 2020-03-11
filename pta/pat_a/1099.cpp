#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int lcd, rcd;
    int data;
    int left, right;
} nodes[100];

int dat[100];

int cnt(int root) {
    if (root == -1) {
        return 0;
    }
    nodes[root].lcd = cnt(nodes[root].left);
    nodes[root].rcd = cnt(nodes[root].right);
    return nodes[root].lcd + nodes[root].rcd + 1;
}

void fill(int root, int start) {
    if (root == -1) {
        return;
    }
    int pos = start + nodes[root].lcd;
    fill(nodes[root].left, start);
    fill(nodes[root].right, pos + 1);
    nodes[root].data = dat[pos];
}

vector<int> order;  // TODO return vector
void levelOrder(int root) {
    queue<int> q;
    q.push(root);
    int cur;
    while (q.size()) {
        cur = q.front();
        if (nodes[cur].left >= 0) q.push(nodes[cur].left);
        if (nodes[cur].right >= 0) q.push(nodes[cur].right);
        order.push_back(cur);
        q.pop();
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &nodes[i].left, &nodes[i].right);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", dat + i);
    }
    sort(dat, dat + n);
    cnt(0), fill(0, 0), levelOrder(0);  //按顺序的
    for (int i = 0; i < n; i++) {
        printf("%d", nodes[order[i]].data);
        printf(i == n - 1 ? "\n" : " ");
    }
    return 0;
}