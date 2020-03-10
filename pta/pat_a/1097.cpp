#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
struct Node {
    int data;
    int add, next;
} nodes[100010];
int cnt[10001];

int main() {
    int head, n;
    cin >> head >> n;
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0, ad; i < n; i++) {
        scanf("%d", &ad);
        scanf("%d %d", &nodes[ad].data, &nodes[ad].next);
        nodes[ad].add = ad;
    }
    vector<Node> remain, lose;
    while (head > -1) {
        if (cnt[abs(nodes[head].data)]) {
            lose.push_back(nodes[head]);
        } else {
            remain.push_back(nodes[head]);
            cnt[abs(nodes[head].data)] = 1;
        }
        head = nodes[head].next;
    }
    for (int i = 0; i < remain.size(); i++) {
        printf("%05d %d", remain[i].add, remain[i].data);
        if (i == remain.size() - 1) {
            printf(" -1\n");
        } else {
            printf(" %05d\n", remain[i + 1].add);
        }
    }
    for (int i = 0; i < lose.size(); i++) {
        printf("%05d %d", lose[i].add, lose[i].data);
        if (i == lose.size() - 1) {
            printf(" -1\n");
        } else {
            printf(" %05d\n", lose[i + 1].add);
        }
    }
    return 0;
}