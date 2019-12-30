#
# @lc app=leetcode.cn id=326 lang=python3
#
# [326] 3的幂
#

# @lc code=start
import math
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        while n>1:
            n=n/3
        return n==1 

# @lc code=end

