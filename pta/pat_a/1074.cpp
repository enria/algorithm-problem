#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int data;
    int next;
} nodes[100001];

int main() {
    int head, n, k;
    cin >> head >> n >> k;
    for (int i = 0, _add; i < n; i++) {
        scanf("%d", &_add);
        scanf("%d %d", &nodes[_add].data, &nodes[_add].next);
    }

    vector<int> origin;
    while (head > -1) {  //可能之间会有断层，先收集有效的，后面可以减少很多判断
        origin.push_back(head);
        head = nodes[head].next;
    }
    vector<int> result;  //保存结果，不是直接在里面判断输出，代码会简洁很多
    stack<int> stk;
    n = origin.size();
    for (int i = 0; i < n; i += k) {
        if (i + k > n) {
            for (; i < n; i++) {
                result.push_back(origin[i]);
            }
        } else {
            for (int j = i + k - 1; j >= i; j--) {
                result.push_back(origin[j]);
            }
        }
    }
    for (int i = 0, ad; i < result.size(); i++) {
        ad = result[i];
        if (i < result.size() - 1) {
            printf("%05d %d %05d\n", ad, nodes[ad].data, result[i + 1]);
        } else {
            printf("%05d %d -1\n", ad, nodes[ad].data);
        }
    }

    return 0;
}