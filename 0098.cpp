// Link: https://leetcode.com/problems/validate-binary-search-tree/
// Runtime: 12 ms 
// Memory: 21.5 MB

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
    bool isValidBST(TreeNode* root) 
    {
        return isTree(root, LONG_MIN, LONG_MAX);
    }
    
private:
    bool isTree(TreeNode* root, long min, long max)
    {
        if (root == nullptr) return true;
        else if ((root->val < max) && (root->val > min)) 
            return isTree(root->left, min, root->val) && 
                   isTree(root->right, root->val, max);
        else return false;
    }
};
