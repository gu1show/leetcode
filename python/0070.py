# Link: https://leetcode.com/problems/climbing-stairs/description/
# Runtime: 34 ms
# Memory: 17.35 MB


class Solution:
    @cache
    def climbStairs(self, n: int) -> int:
        if n < 3:
            return n

        return self.climbStairs(n - 1) + self.climbStairs(n - 2)
