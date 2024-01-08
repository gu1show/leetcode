// Link: https://leetcode.com/problems/range-sum-of-bst/description/
// Runtime: 98 ms 
// Memory: 64.95 MB

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
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        if (root == nullptr)
            return 0;
        else
        {
            int currentSum = 0;
            if ((root->val >= low) && (root->val <= high))
                currentSum += root->val;
            
            return currentSum + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
    }
};
