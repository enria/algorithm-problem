/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

namespace wrap {
void str_reverse(string& str) {
    reverse(str.begin(), str.end());
}
}  // namespace wrap

class Solution {
   public:
    int reverse(int x) {
        bool signal = false;
        if (x < 0)
            signal = true;
        if (x == INT_MIN)
            return 0;
        x = abs(x);
        string as = to_string(x);
        wrap::str_reverse(as);
        long long b = stoll(as);
        if (signal)
            b = -b;
        if (b > INT_MAX || b < INT_MIN) {
            return 0;
        }
        return b;
    }
};
// @lc code=end
