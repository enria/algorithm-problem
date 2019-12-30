/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
   public:
    string convertToTitle(int n) {
        string title = "";
        int y;  //余数
        do {
            n = n - 1;
            y = n % 26;
            n = n / 26;
            title = char(y + 65) + title;
        } while (n > 0);

        return title;
    }
};
// @lc code=end
