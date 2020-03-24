#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

int preOrder[30], postOrder[30];
map<int, int> preIndex, postIndex;

int uncertain = 0;

void build(Node *&root, int pre, int post, int len) {  // root是当前的父结点
    if (len == 0) {
        return;
    }
    if (preOrder[pre] == postOrder[post + len - 1]) {
        if (root) {  //父结点已知，子结点自行决定在左边还是右边，产生不确定性
            uncertain++;
            root->left = (Node *)malloc(sizeof(Node));
            root->left->data = preOrder[pre];
            build(root->left, pre + 1, post, len - 1);
        } else {  //父结点不存存，类似从根开始从头构造
            root = (Node *)malloc(sizeof(Node));
            root->data = preOrder[pre];
            build(root, pre + 1, post, len - 1);
        }
    } else {
        int leftLen = postIndex[preOrder[pre]] - post + 1;
        build(root->left, pre, post, leftLen);
        build(root->right, pre + leftLen, post + leftLen, len - leftLen);
    }
}

vector<int> inOrder;
void buildInOrder(Node *root) {
    if (root) {
        buildInOrder(root->left);
        inOrder.push_back(root->data);
        buildInOrder(root->right);
    }
}

int main() {
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        preOrder[i] = num, preIndex[num] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        postOrder[i] = num, postIndex[num] = i;
    }
    Node *root = 0;  //注意
    build(root, 0, 0, n);
    buildInOrder(root);
    printf(uncertain ? "No\n" : "Yes\n");
    for (int i = 0; i < n; i++) {
        printf("%d", inOrder[i]);
        printf(i == inOrder.size() - 1 ? "\n" : " ");
    }

    return 0;
}