#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct LinkNode {
    int index = -1;
    LinkNode* next = NULL;
};

struct TreeNode {
    string no;
    int* children;
    int cn = 0;
} nodes[101];

map<string, int> dict;

int main() {
    int n, m;
    cin >> n >> m;
    int index = 0;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int level_l = 0, level_c = 0, level_n = 1;
    int next_level_n = 0;
    queue<int> q;
    for (int i = 0; i < m; i++) {
        string no;
        int k, node_index;
        cin >> no >> k;
        TreeNode node;
        node = nodes[dict[no]];
        if (!dict[no]) {
            node.no = no;
            nodes[index] = node;
            node_index = index;
            dict[no] = index++;
        } else {
            node_index = dict[no];
        }
        node.children = (int*)malloc(k * sizeof(int));
        node.cn = k;
        for (int j = 0; j < k; j++) {
            string cno;
            cin >> cno;
            int cindex;
            if (dict[cno]) {
                cindex = dict[cno];
            } else {
                TreeNode cnode;
                cnode.no = cno;
                nodes[index] = cnode;
                cindex = index;
                dict[cno] = index++;
            }
            node.children[j] = cindex;
        }
        nodes[node_index] = node;
    }
    q.push(dict["01"]);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if (!nodes[c].cn) {
            level_l++;
        } else {
            next_level_n += nodes[c].cn;
            for (int i = 0; i < nodes[c].cn; i++) {
                q.push(nodes[c].children[i]);
            }
        }
        if (++level_c == level_n) {
            if (nodes[c].no == "01") {
                cout << level_l;
            } else {
                cout << " " << level_l;
            }
            level_c = 0;
            level_l = 0;
            level_n = next_level_n;
            next_level_n = 0;
        }
    }
    cout << endl;
    return 0;
}