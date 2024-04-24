# Link: https://leetcode.com/problems/n-th-tribonacci-number/description/
# Runtime: 31 ms
# Memory: 16.55 MB

class Solution:
    @cache
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        elif 1 <= n <= 2:
            return 1
        else:
            return self.tribonacci(n - 1) + self.tribonacci(n - 2) + self.tribonacci(n - 3)
