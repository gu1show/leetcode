// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Runtime: 0 ms
// Memory: 8.3 MB

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
    std::vector<int> inorderTraversal(TreeNode* root) 
    {
        traverseInorder(root);
        return values;
    }
    
private:
    std::vector<int> values;
    
    void traverseInorder(TreeNode* root)
    {
        if (root != nullptr)
        {
            if (root->left != nullptr) traverseInorder(root->left);
            values.push_back(root->val);
            if (root->right != nullptr) traverseInorder(root->right);
        }
    }
};
