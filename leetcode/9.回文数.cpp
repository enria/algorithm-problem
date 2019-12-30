/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
   public:
    bool isPalindrome(int x) {
        string xs = to_string(x);
        for (int i = 0; i < xs.length() / 2; i++) {
            if (xs.at(i) != xs.at(xs.length() - 1 - i))
                return false;
        }
        return true;
    }
};
// @lc code=end
