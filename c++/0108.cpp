// Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Runtime: 7 ms
// Memory: 21.4 MB

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
  TreeNode *sortedArrayToBST(const std::vector<int> &nums) {
    return createBST(nums, 0, nums.size());
  }

private:
  TreeNode *createBST(const std::vector<int> &nums, int left, int right) {
    if (left < right) {
      TreeNode *newNode = new TreeNode(nums[(left + right) / 2]);

      newNode->left = createBST(nums, left, (left + right) / 2);
      newNode->right = createBST(nums, (left + right) / 2 + 1, right);

      return newNode;
    } else
      return nullptr;
  }
};
