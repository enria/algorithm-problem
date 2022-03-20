class NumArray:

    def __init__(self, nums):
        self.sum=[0]*(len(nums)+1)
        s=0
        for i in range(len(nums)):
            s+=nums[i]
            self.sum[i+1]=s

    def sumRange(self, left: int, right: int) -> int:
        return self.sum[right+1]-self.sum[left]

        

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)

numArray = NumArray([-2, 0, 3, -5, 2, -1])
print(numArray.sumRange(0, 2)) 
print(numArray.sumRange(2, 5)) 
print(numArray.sumRange(0, 0)) 
