// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// The first solution
// Runtime: 30 ms
// Memory: 14.3 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        isFindNode(root, p, q);
        return ancestor;
    }
    
private:
    TreeNode* ancestor;
    bool isFindNode(TreeNode* currentNode, TreeNode* p, TreeNode* q)
    {
        if (currentNode == nullptr) return false;
        else
        {
            int left = 0;
            if (isFindNode(currentNode->left, p, q)) left = 1;
            
            int right = 0;
            if (isFindNode(currentNode->right, p, q)) right = 1;
            
            int middle = 0;
            if ((currentNode == p) || (currentNode == q)) middle = 1;
            
            if (left + right + middle >= 2) ancestor = currentNode;
            
            return (left + middle + right) > 0;
        }
    }
};

// The second solution
// Runtime: 19 ms
// Memory: 14.2 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if ((root == nullptr) || (root == p) || (root == q)) return root;
        else
        {
            TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
            TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);
            
            if (leftNode == nullptr) return rightNode;
            else if (rightNode == nullptr) return leftNode;
            else return root;
        }
    }
};

