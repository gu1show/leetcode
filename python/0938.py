# Link: https://leetcode.com/problems/range-sum-of-bst/description/
# Runtime: 120 ms
# Memory: 24.41 MB

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if root:
            current_sum = 0
            if low <= root.val <= high:
                current_sum += root.val

            return (
                current_sum
                + self.rangeSumBST(root.left, low, high)
                + self.rangeSumBST(root.right, low, high)
            )
        else:
            return 0
