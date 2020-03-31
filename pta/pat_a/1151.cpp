#include <iostream>
#include <map>
#include <vector>

using namespace std;

int inOrder[10000], preOrder[10000];
map<int, int> inIndex;

struct Node {
    int data;
    Node *left, *right, *parent;
};
map<int, Node *> nodeIndex;

void build(Node *parent, Node *&root, int inStart, int preStart, int len) {
    if (len) {
        root = (Node *)malloc(sizeof(Node));
        root->data = preOrder[preStart];
        root->parent = parent;
        nodeIndex[root->data] = root;
        int leftLen = inIndex[root->data] - inStart;
        build(root, root->left, inStart, preStart + 1, leftLen);
        build(root, root->right, inIndex[root->data] + 1,
              preStart + leftLen + 1, len - 1 - leftLen);
    }
}

vector<int> find_parent(int num) {
    vector<int> result;
    Node *cur = nodeIndex[num];
    while (cur) {
        result.insert(result.begin(), cur->data);
        cur = cur->parent;
    }
    return result;
}

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", inOrder + i);
        inIndex[inOrder[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", preOrder + i);
    }
    Node *root;
    build(NULL, root, 0, 0, n);
    for (int i = 0, v1, v2; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        vector<int> v1a = find_parent(v1), v2a = find_parent(v2);
        if (v1a.empty() || v2a.empty()) {
            if (v1a.empty() && v2a.empty()) {
                printf("ERROR: %d and %d are not found.\n", v1, v2);
            } else {
                printf("ERROR: %d is not found.\n", v1a.empty() ? v1 : v2);
            }
            continue;
        }
        int anc;
        for (int j = 0; j < v1a.size() && j < v2a.size(); j++) {
            if (v1a[j] == v2a[j]) {
                anc = v1a[j];
            } else {
                break;
            }
        }
        if (anc == v1 || anc == v2) {
            printf("%d is an ancestor of %d.\n", anc, anc == v1 ? v2 : v1);
        } else {
            printf("LCA of %d and %d is %d.\n", v1, v2, anc);
        }
    }
    return 0;
}