// Link: https://leetcode.com/problems/path-sum-ii/
// Runtime: 15 ms
// Memory: 38.8 MB

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
  std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum) {
    std::vector<int> way;
    addPaths(root, way, targetSum);

    return paths;
  }

private:
  std::vector<std::vector<int>> paths;

  void addPaths(TreeNode *root, std::vector<int> way, int currentSum) {
    if (root != nullptr) {
      currentSum -= root->val;
      way.push_back(root->val);
      if ((currentSum == 0) && (root->left == nullptr) &&
          (root->right == nullptr))
        paths.push_back(way);
      else {
        addPaths(root->left, way, currentSum);
        addPaths(root->right, way, currentSum);
      }
    }
  }
};
