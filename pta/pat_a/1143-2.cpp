#include <iostream>
#include <set>
#include <vector>

using namespace std;

int nums[10000];
set<int> numIndex;
int m, n;
void ancestors(int num, vector<int> &ans) {
    if (numIndex.find(num) == numIndex.end()) return;
    int last_an;
    for (int i = 0; i < n; i++) {
        if (nums[i] == num) {
            ans.push_back(num);
            break;
        }
        if (i == 0) {
            last_an = nums[i];
            ans.push_back(last_an);
            continue;
        }
        if (num > last_an) {
            if (nums[i] > last_an) {
                ans.push_back(nums[i]);
                last_an = nums[i];
            }
        } else {
            ans.push_back(nums[i]);
            last_an = nums[i];
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", nums + i);
        numIndex.insert(nums[i]);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        vector<int> aa, ab;
        ancestors(a, aa), ancestors(b, ab);
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
        int lca = nums[0];
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