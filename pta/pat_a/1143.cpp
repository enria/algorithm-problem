#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

void insert(Node *&root, int data) {
    if (root) {
        insert(data < root->data ? root->left : root->right, data);
    } else {
        root = (Node *)malloc(sizeof(Node));
        root->data = data;
    }
}
void ancestors(Node *root, int num, vector<int> &ans) {
    if (!root) {
        ans.clear();
        return;
    }
    if (root->data == num) {
        ans.push_back(root->data);
    } else {
        ans.push_back(root->data);
        if (num < root->data) {
            ancestors(root->left, num, ans);
        } else {
            ancestors(root->right, num, ans);
        }
    }
}

int main() {
    int m, n, num;
    cin >> m >> n;
    Node *root = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        insert(root, num);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        vector<int> aa, ab;
        ancestors(root, a, aa), ancestors(root, b, ab);
        if (aa.empty() && ab.empty()) {
            printf("ERROR: %d and %d are not found.\n", a, b);
            continue;
        } else if (aa.empty()) {
            printf("ERROR: %d is not found.\n", a);
            continue;
        } else if (ab.empty()) {
            printf("ERROR: %d is not found.\n", b);
            continue;
        }
        int lca = root->data;
        for (int i = 0; i < aa.size() && i < ab.size(); i++) {
            if (aa[i] == ab[i]) {
                lca = aa[i];
            } else {
                break;
            }
        }
        if (lca == a) {
            printf("%d is an ancestor of %d.\n", a, b);
        } else if (lca == b) {
            printf("%d is an ancestor of %d.\n", b, a);
        } else {
            printf("LCA of %d and %d is %d.\n", a, b, lca);
        }
    }

    return 0;
}