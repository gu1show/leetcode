# Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
# Runtime: 502 ms
# Memory: 51.2 MB

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import queue


class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        
        nodes_and_depth = queue.Queue()
        nodes_and_depth.put((root, 1))
        is_found = False
        minimum_depth = 0
        while (not nodes_and_depth.empty()) and (not is_found):
            node, depth = nodes_and_depth.get()

            if node.left != None:
                nodes_and_depth.put((node.left, depth + 1))
            if node.right != None:
                nodes_and_depth.put((node.right, depth + 1))
            
            if node.left == None and node.right == None:
                minimum_depth = depth
                is_found = True
        
        return minimum_depth
