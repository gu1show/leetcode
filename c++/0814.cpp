// Link: https://leetcode.com/problems/binary-tree-pruning/
// Runtime: 3 ms
// Memory: 9.3 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *pruneTree(TreeNode *root) {
    if (isRemaining(root))
      return root;
    else
      return nullptr;
  }

private:
  bool isRemaining(TreeNode *root) {
    if (root != nullptr) {
      bool hasOneLeft = isRemaining(root->left);
      bool hasOneRight = isRemaining(root->right);

      if (!hasOneLeft) {
        TreeNode *node = root->left;
        root->left = nullptr;
        delete node;
      }

      if (!hasOneRight) {
        TreeNode *node = root->right;
        root->right = nullptr;
        delete node;
      }

      return hasOneLeft || hasOneRight || root->val == 1;
    } else
      return false;
  }
};
