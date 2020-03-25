#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int n, inOrder[30], postOrder[30];
map<int, int> inIndex;
vector<int> zigOrder;

struct Node {
    int data;
    Node *left, *right;
};

void build(Node *&root, int is, int ps, int len) {
    if (len) {
        root = (Node *)malloc(sizeof(Node));
        root->data = postOrder[ps + len - 1];
        int leftLen = inIndex[root->data] - is;
        build(root->left, is, ps, leftLen);
        build(root->right, inIndex[root->data] + 1, ps + leftLen,
              len - leftLen - 1);
    }
}

void insertZig(vector<int> level, bool reverse) {
    if (reverse) {
        zigOrder.insert(zigOrder.end(), level.rbegin(), level.rend());
    } else {
        zigOrder.insert(zigOrder.end(), level.begin(), level.end());
    }
}

void zig(Node *root) {
    queue<Node *> q;
    q.push(root);
    int level = 1, cln = 1, nln = 0, cnt = 0;
    vector<int> level_node;
    while (!q.empty()) {
        Node *cur = q.front();
        level_node.push_back(cur->data), q.pop();
        if (cur->left) {
            nln++;
            q.push(cur->left);
        }
        if (cur->right) {
            nln++;
            q.push(cur->right);
        }
        if (++cnt == cln) {
            insertZig(level_node, level % 2 == 1);
            level++;
            cln = nln, nln = 0, cnt = 0;
            level_node.clear();
        }
    }
};

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", inOrder + i);
        inIndex[inOrder[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", postOrder + i);
    }
    Node *root = 0;
    build(root, 0, 0, n);
    zig(root);
    for (int i = 0; i < n; i++) {
        printf("%d", zigOrder[i]);
        printf(i == n - 1 ? "\n" : " ");
    }
    return 0;
}