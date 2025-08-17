// Link: https://leetcode.com/problems/min-cost-climbing-stairs/
// Runtime: 5 ms
// Memory: 14.3 MB

class Solution {
public:
  int minCostClimbingStairs(const std::vector<int> &cost) {
    std::vector<int> minCost = cost;
    for (int i = 2; i < static_cast<int>(minCost.size()); i++)
      minCost[i] += std::min(minCost[i - 1], minCost[i - 2]);

    return std::min(minCost[minCost.size() - 1], minCost[minCost.size() - 2]);
  }
};
