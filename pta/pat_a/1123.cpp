#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

void leftPovit(Node *&root) {
    Node *left = root->left;
    root->left = left->right;
    left->right = root;
    root = left;
}

void rightPovit(Node *&root) {
    Node *right = root->right;
    root->right = right->left;
    right->left = root;
    root = right;
}

int checkBalance(Node *&root, int height) {
    if (!root) return height;
    int leftH = checkBalance(root->left, height);
    int rightH = checkBalance(root->right, height);
    if (leftH - rightH >= 2) {
        if (checkBalance(root->left->left, 0) >
            checkBalance(root->left->right, 0)) {  // LL型
            leftPovit(root);
        } else {  // LR型
            rightPovit(root->left);
            leftPovit(root);
        }
    } else if (rightH - leftH >= 2) {
        if (checkBalance(root->right->right, 0) >
            checkBalance(root->right->left, 0)) {  // RR型
            rightPovit(root);
        } else {  // RL型
            leftPovit(root->right);
            rightPovit(root);
        }
    }
    return max(leftH, rightH) + 1;
}

void insert(Node *&root, int data) {
    if (!root) {
        root = (Node *)malloc(sizeof(Node));
        root->data = data;
    } else {
        insert(data > root->data ? root->right : root->left, data);
        checkBalance(root, 0);
    }
}

vector<int> levelOrder;

bool level(Node *root) {
    queue<Node *> q;
    q.push(root);
    bool isC = true, occur = false;
    while (!q.empty()) {
        Node *cur = q.front();
        q.pop();
        levelOrder.push_back(cur->data);
        if (cur->left) {
            q.push(cur->left);
            if (occur) isC = false;
        } else {
            occur = true;
        }
        if (cur->right) {
            q.push(cur->right);
            if (occur) isC = false;
        } else {
            occur = true;
        }
    }
    return isC;
}

int main() {
    int n, num;
    cin >> n;
    Node *root = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        insert(root, num);
    }
    bool isC = level(root);
    for (int i = 0; i < n; i++) {
        printf("%d", levelOrder[i]);
        printf(i == n - 1 ? "\n" : " ");
    }
    printf(isC ? "YES\n" : "NO\n");
    return 0;
}