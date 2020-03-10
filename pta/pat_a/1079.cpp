#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node {
    float store;
    vector<int> child;
};
double sells = 0, p, r;
// TODO 使用指针数组
Node cache[100010];
void comput(int ri, int level) {
    Node root = cache[ri];
    if (root.child.size()) {
        for (int i = 0; i < root.child.size(); i++) {
            comput(root.child[i], level + 1);
        }
    } else {
        sells += root.store * p * pow(1 + r / 100, level - 1);
        return;
    }
}

int main() {
    int n;
    cin >> n >> p >> r;
    for (int i = 0, k; i < n; i++) {
        scanf("%d", &k);
        if (k == 0) {
            scanf("%f", &cache[i].store);
        } else {
            for (int j = 0, _c; j < k; j++) {
                scanf("%d", &_c);
                cache[i].child.push_back(_c);
            }
        }
    }
    comput(0, 1);
    printf("%.1f\n", sells);
    return 0;
}