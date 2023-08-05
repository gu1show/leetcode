// Link: https://leetcode.com/problems/unique-binary-search-trees-ii/description/
// Runtime: 9 ms
// Memory: 12.52 MB

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
    std::vector<TreeNode*> generateTrees(int n) 
    {
        return generateAllTrees(1, n);
    }

private:
    std::map<std::pair<int, int>, std::vector<TreeNode*>> subtrees;

    std::vector<TreeNode*> generateAllTrees(int left, int right)
    {
        if (left > right) return {nullptr};
        else if (left == right) return {new TreeNode(left)};
        else if (subtrees.find({left, right}) != subtrees.end()) return subtrees[{left, right}];

        std::vector<TreeNode*> allTrees;
        for (int i = left; i < right + 1; i++)
            for (const auto& leftTree : generateAllTrees(left, i - 1))
                for (const auto& rightTree : generateAllTrees(i + 1, right))
                    allTrees.push_back(new TreeNode(i, leftTree, rightTree));

        subtrees[{left, right}] = allTrees;            
        
        return allTrees;
    }
};
