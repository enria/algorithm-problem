#
# @lc app=leetcode.cn id=1155 lang=python3
#
# [1155] 掷骰子的N种方法
#

# @lc code=start
class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        if target>d*f:
            return 0
        i=0
        mem=[[1]]
        for i in range(1,d+1):
            mem.append([])
            for num in range(0,d*f+1):
                c=0
                for fi in range(1,f+1):
                   if(num-fi<0 or num-fi>=len(mem[i-1])):
                       continue
                   c+=mem[i-1][num-fi]
                mem[i].append(c)

        return mem[d][target]%(pow(10,9)+7)    

test=Solution()
t=test.numRollsToTarget(2,6,7)
print(t)

# @lc code=end

