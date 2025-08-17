// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/description/
// Runtime: 0 ms
// Memory: 10.6 MB

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
  std::vector<int> preorderTraversal(TreeNode *root) {
    if (root != nullptr) {
      nodeValues.push_back(root->val);
      preorderTraversal(root->left);
      preorderTraversal(root->right);
    }

    return nodeValues;
  }

private:
  std::vector<int> nodeValues;
};
