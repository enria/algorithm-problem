class Solution:

    def is_prime(self,n):
        if n<=1:return 0
        if n==2 or n==3:return 1
        if n%6!=1 and n%6!=5: return 0
        for i in range(5,int(n**(1/2)),6):
            if n%i==0 or n%(i+2)==0: return 0
        return 1

    def countPrimes(self, n: int) -> int:
        if n<=1:return 0
        cache=[False]*n
        cache[0]=cache[1]=True
        for i in range(2,n):
            if cache[i]:continue
            for j in range(2*i,n,i):
                cache[j]=True
        prime_cnt=len(list(filter(lambda x:not x,cache)))
        return prime_cnt

s=Solution()
print(s.countPrimes(5*(10**6)))
# print(s.countPrimes(1))
# print(s.countPrimes(0))
