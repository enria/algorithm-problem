#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> baseSort(vector<string> nums);

int main(void) {
    int n;
    cout << "enter number count:";
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++) {
        cout << "enter #" << i + 1 << " number:";
        cin >> nums[i];
    }
    nums = baseSort(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
}

vector<string> baseSort(vector<string> nums, bool reverse, int base = 10) {
    vector<vector<string> > buckets(0, vector<string>(0));
    for (int i = 0; i < base; i++) {
        buckets.push_back(vector<string>(0));
    }
    bool change = true;
    int wei = 1;

    while (change) {
        change = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i].length() < wei) {
                buckets[0].push_back(nums[i]);
            } else {
                change = true;
                char c = nums[i][(nums[i].length() - wei)];
                c - 48 <= 9 && c - 48 >= 0 ? buckets[c - 48].push_back(nums[i])
                                           : buckets[0].push_back(nums[i]);
            }
        }
        nums.clear();

        for (int i = 0; i < base; i++) {
            nums.insert(nums.end(), buckets[i].begin(), buckets[i].end());
            buckets[i].clear();
        }
        wei++;
    }
    if (reverse) {
        std::reverse(nums.begin(),nums.end());
    }
    return nums;
}

vector<string> baseSort(vector<string> nums) {
    vector<string> pos(0), neg(0);
    for (int i = 0; i < nums.size(); i++) {
        nums[i][0] == '-' ? neg.push_back(nums[i]) : pos.push_back(nums[i]);
    }
    try {
        pos = baseSort(pos, false);
        neg = baseSort(neg, true);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    nums.clear();
    nums.insert(nums.end(), neg.begin(), neg.end());
    nums.insert(nums.end(), pos.begin(), pos.end());
    return nums;
}
