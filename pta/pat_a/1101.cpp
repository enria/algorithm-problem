#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n], pre_max = 0, post_min = 1e9 + 1;
    pair<int, int> pre_post[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", nums + i);
        pre_post[i].first = pre_max;
        if (nums[i] > pre_max) {
            pre_max = nums[i];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        pre_post[i].second = post_min;
        if (nums[i] < post_min) {
            post_min = nums[i];
        }
    }
    vector<int> candidates;
    for (int i = 0; i < n; i++) {
        if (nums[i] > pre_post[i].first && nums[i] < pre_post[i].second) {
            candidates.push_back(nums[i]);
        }
    }
    sort(candidates.begin(), candidates.end());
    printf("%d\n", candidates.size());
    for (int i = 0; i < candidates.size(); i++) {
        printf("%d", candidates[i]);
        printf(i == candidates.size() - 1 ? "\n" : " ");
    }
    if (candidates.size() == 0) {
        printf("\n");
    }
    return 0;
}