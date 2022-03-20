class Solution:
    def convertToBase7(self, num: int) -> str:
        p=abs(num)
        ps=[]
        while p:
            l=p%7
            ps.append(l)
            p=p//7
        if not ps:
            ps=[0]
        
        if num<0:  
            ps.append("-")
        return "".join([str(x) for x in ps[::-1]])

s=Solution()
print(s.convertToBase7(100))
print(s.convertToBase7(-7))
print(s.convertToBase7(0))

