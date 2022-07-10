// Link: https://leetcode.com/problems/min-cost-climbing-stairs/
// Runtime: 12 ms
// Memory: 13.6 MB

class Solution 
{
public:
    int minCostClimbingStairs(std::vector<int>& cost) 
    {
        for (int i = 2; i < cost.size(); i++)
            cost[i] += std::min(cost[i - 1], cost[i - 2]);
        
        return std::min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};
