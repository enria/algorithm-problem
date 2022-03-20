from random import random
class Solution:

    def __init__(self, w):
        self.w=w
        self.all_w=sum(w)
        self.eps=1/self.all_w
        self.ps=[0]
        for i in range(1,len(w)):
            self.ps.append(self.ps[i-1]+self.w[i-1])

    def search(self,c):
        r=[0,len(self.w)]
        while True:
            ct=(r[0]+r[1])//2
            if self.ps[ct]<=c:
                if ct+1>=len(self.w) or self.ps[ct+1]>c:
                    return ct
                else:
                    r=[ct,r[1]]
            else:
                r=[r[0],ct]


    def pickIndex(self) -> int:
        p=random()
        c=int(p//self.eps)
        return self.search(c)





# Your Solution object will be instantiated and called as such:
obj = Solution([1,3])
print(obj.pickIndex())