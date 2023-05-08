// Link: https://leetcode.com/problems/add-one-row-to-tree/
// Runtime: 43 ms
// Memory: 24.9 MB

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
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        else
        {
            addNodes(root, val, depth - 1);
            return root;
        }
    }
    
private:
    void addNodes(TreeNode* root, int val, int targetDepth)
    {
        if (root != nullptr)
        {
            if (targetDepth == 1)
            {
                TreeNode* temp = root->left;
                root->left = new TreeNode(val);
                root->left->left = temp;
                temp = root->right;
                root->right = new TreeNode(val);
                root->right->right = temp;
            }
            else
            {
                addNodes(root->left, val, targetDepth - 1);
                addNodes(root->right, val, targetDepth - 1);
            }
        }
    }
};
