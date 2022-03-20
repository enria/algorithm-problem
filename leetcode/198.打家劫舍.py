class Solution:
    def rob(self, nums) -> int:
        dp=[0]*(len(nums))
        for i in range(0,len(nums)):
            l2=dp[i-3] if i>=3 else 0
            l1=dp[i-2] if i>=2 else 0
            dp[i]=nums[i]+max(l1,l2)
        return max(dp)

s=Solution()
print(s.rob([1,2,3,1]))