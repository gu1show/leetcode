// Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// Runtime: 175 ms
// Memory: 86.3 MB

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
  int goodNodes(TreeNode *root) {
    dfs(root, root->val);
    return numberOfGoodNodes;
  }

private:
  int numberOfGoodNodes = 0;

  void dfs(TreeNode *root, int maxValue) {
    if (root != nullptr) {
      if (root->val >= maxValue) {
        numberOfGoodNodes++;
        maxValue = root->val;
      }

      dfs(root->left, maxValue);
      dfs(root->right, maxValue);
    }
  }
};
