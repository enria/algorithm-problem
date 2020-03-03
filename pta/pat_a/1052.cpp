#include <algorithm>
#include <iostream>
#include <vector>

//出错了先看看输入输出格式

using namespace std;
struct Node {
    int address, next = -1;
    int key;
} dat[100000];
int main() {
    int n, first;
    scanf("%d %d", &n, &first);
    int addr, key, next;

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &addr, &key, &next);
        dat[addr].address = addr, dat[addr].key = key, dat[addr].next = next;
    }
    vector<Node> exist;
    while (first >= 0) {
        exist.push_back(dat[first]);
        first = dat[first].next;
    }

    sort(exist.begin(), exist.end(),
         [](Node a, Node b) -> bool { return a.key < b.key; });
    if (exist.size()) {
        printf("%lu %05d\n", exist.size(), exist[0].address);
        for (int i = 0; i < exist.size(); i++) {
            printf("%05d %d", exist[i].address, exist[i].key);
            if (i == exist.size() - 1) {
                printf(" -1\n");
            } else {
                printf(" %05d\n", exist[i + 1].address);
            }
        }
    } else {
        printf("0 -1\n");
    }
    return 0;
}