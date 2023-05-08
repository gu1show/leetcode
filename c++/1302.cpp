// Link: https://leetcode.com/problems/deepest-leaves-sum/
// The first solution
// Runtime: 204 ms
// Memory: 61.8 MB

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
    int deepestLeavesSum(TreeNode* root) 
    {
        if (root == nullptr) return 0;
        nodes.push(root);
        nodes.push(nullptr);
        int sum = 0;
        while (nodes.size() > 1)
        {
            TreeNode* node = nodes.front();
            nodes.pop();
            if (node == nullptr)
            {
                sum = 0;
                nodes.push(nullptr);
            }
            else
            {
                sum += node->val;
                if (node->left != nullptr) nodes.push(node->left);
                if (node->right != nullptr) nodes.push(node->right);
            }
        }
        
        return sum;
    }
private:
    std::queue<TreeNode*> nodes;
};

// The second solution
// Runtime: 111 ms
// Memory: 59.7 MB

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
    int deepestLeavesSum(TreeNode* root) 
    {       
        if (root == nullptr) return 0;
        else
        {
            int maxHeight = -1, maxSum = 0, height = 0;
            dfs(root, maxSum, maxHeight, height);
            return maxSum;
        }
    }
    
    void dfs(TreeNode* root, int& maxSum, int& maxHeight, int height)
    {
        if (root != nullptr)
        {
            height++;
            dfs(root->left, maxSum, maxHeight, height);
            if ((root->left == nullptr) && (root->right == nullptr))
            {
                if (maxHeight < height)
                {
                    maxHeight = height;
                    maxSum = root->val;
                }
                else if (maxHeight == height) maxSum += root->val;
            }
            dfs(root->right, maxSum, maxHeight, height);
        }
    }
};
