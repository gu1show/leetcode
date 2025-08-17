// Link: https://leetcode.com/problems/leaf-similar-trees/description/
// Runtime: 3 ms
// Memory: 13.26 MB

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
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    std::vector<int> firstTreeLeafs, secondTreeLeafs;

    getLeafs(root1, firstTreeLeafs);
    getLeafs(root2, secondTreeLeafs);

    return firstTreeLeafs == secondTreeLeafs;
  }

private:
  void getLeafs(TreeNode *root, std::vector<int> &leafs) {
    if (root != nullptr) {
      if ((root->left == nullptr) && (root->right == nullptr))
        leafs.push_back(root->val);

      getLeafs(root->left, leafs);
      getLeafs(root->right, leafs);
    }
  }
};
