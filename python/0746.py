# Link: https://leetcode.com/problems/min-cost-climbing-stairs/description/
# Runtime: 55 ms
# Memory: 16.22 MB


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        min_cost = cost[:]
        for i in range(2, len(min_cost)):
            min_cost[i] += min(min_cost[i - 1], min_cost[i - 2])

        return min(min_cost[-1], min_cost[-2])
