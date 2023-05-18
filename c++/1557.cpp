// Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
// Runtime: 312 ms
// Memory: 94.1 MB

class Solution 
{
public:
    std::vector<int> findSmallestSetOfVertices(int n,
                                               const std::vector<std::vector<int>>& edges) 
    {
        std::vector<int> waysToNodes(n);
        for (const auto& edge : edges)
            waysToNodes[edge[1]]++;
        
        std::vector<int> unreachableNodes;
        for (int i = 0; i < n; i++)
            if (waysToNodes[i] == 0)
                unreachableNodes.push_back(i);
        
        return unreachableNodes;
    }
};
