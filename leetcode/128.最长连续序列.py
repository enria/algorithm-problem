class Solution:
    def longestConsecutive(self, nums) -> int:
        num_set=set(nums)
        max_l=0
        for i in nums:
            if i not in num_set:continue
            l,r=i-1,i+1
            num_set.remove(i)
            while l in num_set:
                num_set.remove(l)
                l-=1
            while r in num_set:
                num_set.remove(r)
                r+=1
            _l=r-l-1
            if _l>max_l:
                max_l=_l
        return max_l

s=Solution()
print(s.longestConsecutive([0,3,7,2,5,8,4,6,0,1]))



        