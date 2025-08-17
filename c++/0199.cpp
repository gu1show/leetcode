// Link: https://leetcode.com/problems/binary-tree-right-side-view/
// Runtime: 4 ms
// Memory: 12 MB

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
  std::vector<int> rightSideView(TreeNode *root) {
    addNodes(root, 0);
    return nodeValues;
  }

private:
  std::vector<int> nodeValues;

  void addNodes(TreeNode *root, int depth) {
    if (root != nullptr) {
      if (nodeValues.size() == depth)
        nodeValues.push_back(root->val);

      addNodes(root->right, depth + 1);
      addNodes(root->left, depth + 1);
    }
  }
};
