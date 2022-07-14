// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Runtime: 34 ms
// Memory: 26.4 MB

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
    TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder) 
    {
        for (int i = 0; i < inorder.size(); i++)
            nodeValues[inorder[i]] = i;
        
        return createTree(preorder, 0, preorder.size() - 1);
    }
    
    TreeNode* createTree(const std::vector<int>& preorder, int left, int right)
    {
        if (left > right) return nullptr;
        else
        {
            TreeNode* root = new TreeNode();
            int value = preorder[preorderIndex];
            root->val = value;
            preorderIndex++;
            
            root->left = createTree(preorder, left, nodeValues[value] - 1);
            root->right = createTree(preorder, nodeValues[value] + 1, right);
            
            return root;
        }        
    }
        
private:
    std::unordered_map<int, int> nodeValues;
    int preorderIndex = 0;
};
