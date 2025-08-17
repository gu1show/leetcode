// Link: https://leetcode.com/problems/construct-string-from-binary-tree/
// Runtime: 27 ms
// Memory: 26 MB

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
  std::string tree2str(TreeNode *root) {
    if (root == nullptr)
      return "";
    else if ((root->left == nullptr) && (root->right == nullptr))
      return std::to_string(root->val);
    else if (root->right == nullptr)
      return std::to_string(root->val) + "(" + tree2str(root->left) + ")";
    else
      return std::to_string(root->val) + "(" + tree2str(root->left) + ")(" +
             tree2str(root->right) + ")";
  }
};
