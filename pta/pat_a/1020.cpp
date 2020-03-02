#include <iostream>
#include <queue>

using namespace std;
int post[30];
int in[30];
struct btn {
    int data = -1;
    btn *left, *right;
};

void to_tree(btn *root, int pof, int inf, int n) {
    if (n == 0) {
        return;
    }
    root->data = post[pof];
    if (n == 1) {
        return;
    }
    for (int i = inf; i < inf + n; i++) {
        if (in[i] == root->data) {
            int ls = i - inf, rs = n - 1 - ls;
            root->left = (btn *)malloc(sizeof(btn));
            root->right = (btn *)malloc(sizeof(btn));
            to_tree(root->left, pof - rs - 1, inf, ls);
            to_tree(root->right, pof - 1, i + 1, rs);
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    btn *root = (btn *)malloc(sizeof(btn));
    to_tree(root, n - 1, 0, n);
    queue<btn *> q;
    q.push(root);
    int pn = 0;
    while (q.size()) {
        int qn = q.size();
        while (qn--) {
            btn *node = q.front();
            printf(pn++ ? " %d" : "%d", node->data);
            if (node->left && node->left->data > 0) {
                q.push(node->left);
            }
            if (node->right && node->right->data > 0) {
                q.push(node->right);
            }
            q.pop();
        }
    }
    cout<<endl;
    return 0;
}