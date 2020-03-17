#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int nums[1000];

struct Node {
    int data;
    Node *left, *right;
};

void build(Node *root, int start, int end) {  //左闭右开
    if (end - start == 1) {
        root->data = nums[start];
        return;
    }
    int level = (int)log2(end - start + 1);
    int leftc, rightc;
    leftc = pow(2, level - 1) - 1, rightc = pow(2, level - 1) - 1;
    if (end - start - 1 - (leftc + rightc) <= leftc + 1) {
        leftc += end - start - 1 - (leftc + rightc);
    } else {
        leftc += leftc + 1;
        rightc += end - start - 1 - (leftc + rightc);
    }
    root->data = nums[start + leftc];
    if (leftc) {
        root->left = (Node *)malloc(sizeof(Node));
        build(root->left, start, start + leftc);
    }
    if (rightc) {
        root->right = (Node *)malloc(sizeof(Node));
        build(root->right, start + leftc + 1, end);
    }
}

vector<int> order;

void level(Node *root) {
    queue<Node *> q;
    q.push(root);
    while (q.size()) {
        Node *cur = q.front();
        order.push_back(cur->data);
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
        q.pop();
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", nums + i);
    }
    sort(nums, nums + n);
    Node *root = (Node *)malloc(sizeof(Node));
    build(root, 0, n);
    level(root);
    for (int i = 0; i < n; i++) {
        printf("%d", order[i]);
        printf(i == order.size() - 1 ? "\n" : " ");
    }
    return 0;
}