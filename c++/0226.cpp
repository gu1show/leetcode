// Link: https://leetcode.com/problems/invert-binary-tree/description/
// Runtime: 4 ms
// Memory: 9.8 MB

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
  TreeNode *invertTree(TreeNode *root) {
    invert(root);

    return root;
  }

private:
  void invert(TreeNode *root) {
    if (root != nullptr) {
      std::swap(root->left, root->right);

      invert(root->left);
      invert(root->right);
    }
  }
};
