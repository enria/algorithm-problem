n=int(input())
nums=[int(x) for x in input().split()]

dp=[[0]*n for i in range(n)]
for i in range(n):
    dp[i][i]=0

cur=0
for i in range(n):
    if nums[i]==i+1:
        cur+=1

max_inc=0

for i in range(1,n):
    for j in range(n-i):
        org,inc=0,0
        if j+i+1==nums[j+i]:
            org+=1
        if j+1==nums[j]:
            org+=1

        if j+1==nums[j+i]:
            inc+=1
        if j+i+1==nums[j]:
            inc+=1
        dp[j][j+i]=(inc-org)+dp[j+1][j+i-1]
        if max_inc<dp[j][j+i-1]:
            max_inc=dp[j][j+i-1]
        # print(j,j+i,org,inc)
# print(dp)
# print(cur)

print(cur+max_inc)

