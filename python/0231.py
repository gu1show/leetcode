# Link: https://leetcode.com/problems/power-of-two/description/
# Runtime: 29 ms
# Memory: 16.57 MB


class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n < 1:
            return False

        return math.fabs(math.log2(n) - int(math.log2(n))) < sys.float_info.epsilon
