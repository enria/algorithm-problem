# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import random
class Solution:

    def __init__(self, head):
        self.nums=[]
        cur=head
        while cur:
            self.nums.append(cur.val)
            cur=cur.next

    def getRandom(self) -> int:
        idx=random.randint(0,len(self.nums)-1)
        return self.nums[idx]



# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()