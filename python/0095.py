# Link: https://leetcode.com/problems/unique-binary-search-trees-ii/description/
# Runtime: 52 ms
# Memory: 17.5 MB

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        return self.__generate_all_trees(1, n)
    
    @cache
    def __generate_all_trees(self, left: int, right: int) -> List[Optional[TreeNode]]:
        if left > right: return [None]
        elif left == right: return [TreeNode(left)]

        all_trees = []
        for val in range(left, right + 1):
            for left_tree in self.__generate_all_trees(left, val - 1):
                for right_tree in self.__generate_all_trees(val + 1, right):
                    all_trees.append(TreeNode(val, left_tree, right_tree))
        
        return all_trees
