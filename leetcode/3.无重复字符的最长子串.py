class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s: return 0
        max_level=1
        per=[set(x) for x in s] 
        cur=[]
        for level in range(2,min(128,len(s)+1)):
            cur=[]
            for i in range(len(s)-level+1):
                # print("pre",len(per[i]))
                if len(per[i])<level-1:
                    cur.append(set())
                else:
                    ns=per[i] | set(s[i+level-1])
                    # print("len",len(ns))
                    if len(ns)==level: max_level=level
                    cur.append(ns)
            per=cur
            # print(level)
        return max_level

s=Solution()
print(s.lengthOfLongestSubstring("abcabcbb"))