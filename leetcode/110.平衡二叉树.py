#
# @lc app=leetcode.cn id=110 lang=python3
#
# [110] 平衡二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    @staticmethod
    def height(root:TreeNode):
        if not root:
            return 0
        left=Solution.height(root.left)
        right=Solution.height(root.right)
        if left==-1 or right==-1:
            return -1
        if abs(left-right)>=2:
            return -1
        return max(left,right)+1
    def isBalanced(self, root: TreeNode) -> bool:
        return self.height(root)>=0
# @lc code=end

