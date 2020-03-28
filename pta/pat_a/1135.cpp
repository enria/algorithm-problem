#include <iostream>

using namespace std;

int nums[30];
struct Node {
    int data;
    Node *left, *right;
};

void build(Node *&root, int start, int len) {
    if (len == 0) {
        return;
    }
    root = (Node *)malloc(sizeof(Node));
    root->data = nums[start];
    int leftLen = len - 1;
    for (int i = start + 1; i < start + len; i++) {
        if (abs(nums[i]) > abs(nums[start])) {
            leftLen = i - start - 1;
            break;
        }
    }
    build(root->left, start + 1, leftLen);
    build(root->right, start + leftLen + 1, len - leftLen - 1);
}
pair<bool, int> isRBT(Node *root, int bcnt) {
    if (!root) return {true, bcnt + 1};
    if (bcnt == 0 && root->data < 0) return {false, bcnt};

    if (root->data > 0) {
        bcnt++;
    } else {
        if (root->left && root->left->data < 0) return {false, bcnt};
        if (root->right && root->right->data < 0) return {false, bcnt};
    }
    pair<bool, int> left = isRBT(root->left, bcnt);
    pair<bool, int> right = isRBT(root->right, bcnt);
    return {left.first && right.first && left.second == right.second,
            left.second};
}

int main() {
    int k, n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", nums + j);
        }
        Node *root;
        build(root, 0, n);
        printf(isRBT(root, 0).first ? "Yes\n" : "No\n");
    }
    return 0;
}