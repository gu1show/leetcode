// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Runtime: 15 ms
// Memory: 12.7 MB

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
  void flatten(TreeNode *root) {
    if (root != nullptr) {
      TreeNode *nextRightNode = nullptr;
      TreeNode *rightNodeMost = nullptr;

      while (root != nullptr) {
        if (root->left != nullptr) {
          rightNodeMost = getMostRightNode(root->left);
          nextRightNode = root->right;
          root->right = root->left;
          root->left = nullptr;
          rightNodeMost->right = nextRightNode;
        }
        root = root->right;
      }
    }
  }

private:
  TreeNode *getMostRightNode(TreeNode *node) {
    if (node->right == nullptr)
      return node;
    else
      return getMostRightNode(node->right);
  }
};
