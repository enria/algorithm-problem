/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <iostream>

using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        if (!s.size()) {
            return "";
        }
        bool isP[s.size()][s.size()];
        for (int i = 0; i < s.size(); i++) {
            isP[i][i] = true;
        }
        int maxlength = 1, maxfrom = 0;
        for (int i = 2; i <= s.size(); i++) {
            for (int j = 0; j + i <= s.size(); j++) {
                if (s.at(j) == s.at(j + i - 1)) {
                    isP[j][j + i - 1] = i == 2 ? true : isP[j + 1][j + i - 2];
                } else {
                    isP[j][j + i - 1] = false;
                }
                if (isP[j][j + i - 1]) {
                    if (i > maxlength) {
                        maxlength = i, maxfrom = j;
                    }
                }
            }
        }
        return s.substr(maxfrom, maxlength);
    }
};
// @lc code=end

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}