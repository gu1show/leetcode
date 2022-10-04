// Link: https://leetcode.com/problems/path-sum/
// Runtime: 23 ms
// Memory: 21.3 MB

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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if (root == nullptr) return false;
        else return hasSum(root, targetSum, 0);
    }
    
private:
    bool hasSum(TreeNode* root, int targetSum, int currentSum)
    {
        if (root == nullptr) return false;
        else
        {
            currentSum += root->val;
            if ((root->left == nullptr) && 
                (root->right == nullptr) && 
                (currentSum == targetSum)) return true;
            else if ((root->left == nullptr) && 
                     (root->right == nullptr)) return false;
            else
            {
                bool hasNeededSum = hasSum(root->left, targetSum, currentSum) || 
                                    hasSum(root->right, targetSum, currentSum);
            
                return hasNeededSum;
            }
        }
    }
};
