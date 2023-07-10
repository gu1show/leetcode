// Link: https://leetcode.com/problems/solving-questions-with-brainpower/description/
// Runtime: 286 ms
// Memory: 144.7 MB

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
    int minDepth(TreeNode* root) 
    {
        if (root == nullptr) return 0;
        std::queue<std::pair<TreeNode*, int>> nodesAndDepths;
        nodesAndDepths.push(std::make_pair(root, 1));

        int minimumDepth = 0;
        bool isFound = false;
        while ((!nodesAndDepths.empty()) && (!isFound))
        {
            TreeNode* node = nodesAndDepths.front().first;
            int depth = nodesAndDepths.front().second;
            nodesAndDepths.pop();

            if (node->left != nullptr) nodesAndDepths.push(std::make_pair(node->left, depth + 1));
            if (node->right != nullptr) nodesAndDepths.push(std::make_pair(node->right, depth + 1));

            if ((node->left == nullptr) && (node->right == nullptr)) 
            {
                minimumDepth = depth;
                isFound = true;
            }
        }

        return minimumDepth;
    }
};
