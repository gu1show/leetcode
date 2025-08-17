// Link: https://leetcode.com/problems/symmetric-tree/description/
// Runtime: 7 ms
// Memory: 16.6 MB

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
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr)
      return true;
    else
      return isMirrored(root->left, root->right);
  }

private:
  bool isMirrored(TreeNode *node1, TreeNode *node2) {
    if ((node1 == nullptr) && (node2 == nullptr))
      return true;
    else if ((node1 != nullptr) && (node2 != nullptr) &&
             (node1->val == node2->val))
      return isMirrored(node1->left, node2->right) &&
             isMirrored(node1->right, node2->left);
    else
      return false;
  }
};
