/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> cnt;
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]].push_back(i);
        }
        vector<int> result;
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            if (it->first * 2 == target) {
                if (it->second.size() >= 2) {
                    result.push_back(it->second[0]);
                    result.push_back(it->second[1]);
                    break;
                }
            } else if (it->first * 2 < target) {
                if (cnt[target - it->first].size()) {
                    result.push_back(it->second[0]);
                    result.push_back(cnt[target - it->first][0]);
                    break;
                }
            } else {
                break;
            }
        }
        return result;
    }
};
// @lc code=end

int main() { 
    Solution sol;
    return 0; }
