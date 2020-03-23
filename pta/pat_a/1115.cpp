#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

map<int, int> level_cnt;

void insert(Node *&root, int data, int level) {
    if (root) {
        if (data > root->data) {
            insert(root->right, data, level + 1);
        } else {
            insert(root->left, data, level + 1);
        }
    } else {
        root = (Node *)malloc(sizeof(Node));
        root->data = data;
        level_cnt[level]++;
    }
}

int main() {
    Node *root = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insert(root, data, 1);
    }
    vector<pair<int, int>> sorted_level_cnt(level_cnt.begin(), level_cnt.end());

    int n1 = sorted_level_cnt[sorted_level_cnt.size() - 1].second;
    int n2 = sorted_level_cnt.size() - 2 < 0
                 ? 0
                 : sorted_level_cnt[sorted_level_cnt.size() - 2].second;

    printf("%d + %d = %d\n", n1, n2, n1 + n2);
    return 0;
}