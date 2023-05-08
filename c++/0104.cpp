// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
// Runtime: 16 ms
// Memory: 18.8 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if (root == nullptr) return 0;
        else return getMaxDepth(root, 1);
    }

private:
    int getMaxDepth(TreeNode* root, int depth) 
    {
        int maxDepth = depth;
        if (root->left != nullptr) maxDepth = std::max(maxDepth, getMaxDepth(root->left, depth + 1));
        if (root->right != nullptr) maxDepth = std::max(maxDepth, getMaxDepth(root->right, depth + 1));

        return maxDepth;
    }
};
