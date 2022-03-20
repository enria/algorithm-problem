class Solution:
    def longestPalindrome(self, s: str) -> int:
        from collections import Counter
        x=lambda i: i if i%2==0 else i-1
        c=Counter(s)
        cs=[x(c[i]) for i in c]
        cs=sum(cs)
        if cs<len(s): cs+=1
        return cs

s=Solution()
print(s.longestPalindrome("adam"))