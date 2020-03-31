#include <iostream>
#include <stack>
#include <vector>
using namespace std;

pair<bool, int> isHeap(vector<int> nums) {
    pair<bool, int> result = {true, 0};  // 0: not 1:max -1 min
    for (int i = nums.size() - 1; i > 0 && result.first; i--) {
        int p = (i - 1) / 2;
        if (result.second) {
            if (result.second > 0 && nums[p] < nums[i]) result.first = false;
            if (result.second < 0 && nums[p] > nums[i]) result.first = false;
        } else {
            if (nums[p] > nums[i]) result.second = 1;
            if (nums[p] < nums[i]) result.second = -1;
        }
    }
    return result;
}

vector<int> postOrder(vector<int> nums) {
    vector<int> result;
    stack<pair<int, int>> s;
    s.push({0, 0});
    while (!s.empty()) {
        switch (s.top().second) {
            case 0:
                s.top().second = 1;
                if (s.top().first * 2 + 1 < nums.size()) {
                    s.push({s.top().first * 2 + 1, 0});
                }
                break;
            case 1:
                s.top().second = 2;
                if (s.top().first * 2 + 2 < nums.size()) {
                    s.push({s.top().first * 2 + 2, 0});
                }
                break;
            case 2:
                result.push_back(nums[s.top().first]);
                s.pop();
                break;
        }
    }
    return result;
}

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        vector<int> nums(n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &nums[j]);
        }
        pair<bool, int> result = isHeap(nums);
        if (result.first)
            printf(result.second == 1 ? "Max Heap\n" : "Min Heap\n");
        else
            printf("Not Heap\n");
        vector<int> order = postOrder(nums);
        for (int j = 0; j < order.size(); j++) {
            printf("%d", order[j]);
            printf(j == order.size() - 1 ? "\n" : " ");
        }
    }
    return 0;
}