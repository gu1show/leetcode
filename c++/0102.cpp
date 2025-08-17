// Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Runtime: 7 ms
// Memory: 12.5 MB

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
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> values;

    if (root == nullptr)
      return values;
    else {
      std::queue<TreeNode *> nodes;
      nodes.push(root);
      while (nodes.size() > 0) {
        std::vector<int> level;
        int size = static_cast<int>(nodes.size());
        for (int i = 0; i < size; i++) {
          TreeNode *tempNode = nodes.front();
          nodes.pop();
          if (tempNode != nullptr) {
            level.push_back(tempNode->val);
            if (tempNode->left != nullptr)
              nodes.push(tempNode->left);
            if (tempNode->right != nullptr)
              nodes.push(tempNode->right);
          }
        }
        values.push_back(level);
      }
      return values;
    }
  }
};
