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
class BSTIterator
{
public:
    BSTIterator(TreeNode* root) 
    {
        pushLeft(root);
    }
    
    int next() 
    {
        TreeNode* node = nodes.top();
        nodes.pop();
        if (node->right != nullptr) 
            pushLeft(node->right);
        return node->val;
    }
    
    bool hasNext()
    {
        return nodes.size() > 0;   
    }
    
private:
    std::stack<TreeNode*> nodes;
    
    void pushLeft(TreeNode* root)
    {
        while (root != nullptr)
        {
            nodes.push(root);
            root = root->left;
        } 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */