n=int(input())
for i in range(n):
    nums=input().split()
    nums=[int(ni) for ni in nums]
    print("Case #{}: {}".format(i+1,"true" if nums[0]+nums[1]>nums[2] else "false"))