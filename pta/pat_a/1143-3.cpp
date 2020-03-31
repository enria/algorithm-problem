#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

int nums[10000];
set<int> numIndex;

void build(Node *&root, int start, int len) {
    if (len) {
        root = (Node *)malloc(sizeof(Node));
        root->data = nums[start];
        int leftLen = 0;
        for (int i = start + 1; i < start + len; i++) {
            if (nums[i] < root->data) {
                leftLen++;
            } else {
                break;
            }
        }
        build(root->left, start + 1, leftLen);
        build(root->right, leftLen + 1 + start, len - leftLen - 1);
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
    int m, n;
    cin >> m >> n;
    Node *root = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", nums + i);
    }
    build(root, 0, n);
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