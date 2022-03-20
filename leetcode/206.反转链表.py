# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
    def __repr__(self) -> str:
        h=self
        while h:
            print(h.val)
            h=h.next
        return ""

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head: return head
        cur=head
        n=head.next
        cur.next=None
        while n:
            a=n.next
            n.next=cur
            cur=n
            n=a
        return cur

head = [1,2,3,4,5]
h=ListNode()
cur=h
for i in head:
    n=ListNode(i)
    cur.next=n
    cur=n

s=Solution()
print(s.reverseList(h.next))
