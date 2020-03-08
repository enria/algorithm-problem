#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

void insert(Node *root, int data) {
    if (data < root->data) {
        if (root->left) {
            insert(root->left, data);
        } else {
            root->left = (Node *)malloc(sizeof(Node));
            root->left->data = data;
        }
    } else {
        if (root->right) {
            insert(root->right, data);
        } else {
            root->right = (Node *)malloc(sizeof(Node));
            root->right->data = data;
        }
    }
}

void exchangeVal(Node *a, Node *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void l_adjust(Node *root) {
    Node *leftC = root->left;
    root->left = leftC->left;
    leftC->left = leftC->right;
    leftC->right = root->right;
    root->right = leftC;
    exchangeVal(root, leftC);
}

void r_adjust(Node *root) {
    Node *rightC = root->right;
    root->right = rightC->right;
    rightC->right = rightC->left;
    rightC->left = root->left;
    root->left = rightC;
    exchangeVal(root, rightC);
}

//检查并调整AVL
int check(Node *root) {
    if (!root) {
        return 0;
    }
    int leftH = check(root->left);
    int rightH = check(root->right);
    if (abs(leftH - rightH) > 1) {
        if (leftH > rightH) {
            Node *leftC = root->left;
            if (check(leftC->left) > check(leftC->right)) {  // LL型
                l_adjust(root);
            } else {  // LR型
                r_adjust(leftC);
                l_adjust(root);
            }
            
            return leftH - 1 + 1;
        } else {
            Node *rightC = root->right;
            if (check(rightC->right) > check(rightC->left)) {  // RR型
                r_adjust(root);
            } else {
                l_adjust(rightC);
                r_adjust(root);
            }
            return rightH - 1 + 1;
        }
    }
    return max(leftH, rightH) + 1;
}

int main() {
    int n;
    cin >> n;
    Node *root = NULL;
    for (int i = 0, data; i < n; i++) {
        scanf("%d", &data);
        if (root == NULL) {
            root = (Node *)malloc(sizeof(Node));
            root->data = data;
        } else {
            insert(root, data);
        }
        check(root);
    }
    cout << root->data << endl;
    return 0;
}