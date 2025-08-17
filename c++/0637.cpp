// Link: https://leetcode.com/problems/average-of-levels-in-binary-tree/
// The first solution
// Runtime: 21 ms
// Memory: 24.8 MB

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
  std::vector<double> averageOfLevels(TreeNode *root) {
    std::vector<double> average;
    std::queue<TreeNode *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
      long long sumValues = 0;
      short count = 0;
      std::queue<TreeNode *> temp;
      while (!nodes.empty()) {
        TreeNode *node = nodes.front();
        nodes.pop();
        sumValues += node->val;
        count++;
        if (node->left != nullptr)
          temp.push(node->left);
        if (node->right != nullptr)
          temp.push(node->right);
      }
      nodes = temp;
      average.push_back(sumValues / static_cast<double>(count));
    }

    return average;
  }
};

// The second solution
// Runtime: 21 ms
// Memory: 22.6 MB

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
  std::vector<double> averageOfLevels(TreeNode *root) {
    std::vector<double> average;
    std::vector<short> countNodes;
    dfs(root, average, countNodes, 0);

    for (int i = 0; i < countNodes.size(); i++)
      average[i] /= countNodes[i];

    return average;
  }

private:
  void dfs(TreeNode *root, std::vector<double> &average,
           std::vector<short> &countNodes, int level) {
    if (root != nullptr) {
      if (level < average.size()) {
        average[level] += root->val;
        countNodes[level]++;
      } else {
        average.push_back(root->val);
        countNodes.push_back(1);
      }

      dfs(root->left, average, countNodes, level + 1);
      dfs(root->right, average, countNodes, level + 1);
    }
  }
};
