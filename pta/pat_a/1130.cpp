#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
    char data[11];
    int left = -1, right = -1;
} nodes[21];

pair<int, string> toInExp(int root) {  //让上级决定我是否需要加括号
    if (root == -1) {
        return {0, ""};
    } else {
        if (nodes[root].left == -1 && nodes[root].right == -1) {
            return {1, nodes[root].data};
        } else {
            pair<int, string> left = toInExp(nodes[root].left);
            if (left.first > 1) left.second = "(" + left.second + ")";
            pair<int, string> right = toInExp(nodes[root].right);
            if (right.first > 1) right.second = "(" + right.second + ")";
            return {left.first + right.first + 1,
                    left.second + string(nodes[root].data) + right.second};
        }
    }
}

int main() {
    int n;
    cin >> n;
    bool isRoot[n + 1];
    fill(isRoot + 1, isRoot + n + 1, true);
    for (int i = 1; i <= n; i++) {
        scanf("%s %d %d", nodes[i].data, &nodes[i].left, &nodes[i].right);
        if (nodes[i].left > 0) isRoot[nodes[i].left] = false;
        if (nodes[i].right > 0) isRoot[nodes[i].right] = false;
    }
    int root;
    for (int i = 1; i <= n; i++) {
        if (isRoot[i]) {
            root = i;
            break;
        }
    }
    pair<int, string> result = toInExp(root);
    printf("%s\n", result.second.c_str());
    return 0;
}