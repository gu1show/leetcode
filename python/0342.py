# Link: https://leetcode.com/problems/power-of-four/description/
# Runtime: 0 ms
# Memory: 17.82 MB


class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        return (n > 0) and fabs(
            log10(n) / log10(4) - int(log10(n) / log10(4))
        ) < float_info.epsilon
