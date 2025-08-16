# Link: https://leetcode.com/problems/maximum-69-number/description/
# Runtime: 0 ms
# Memory: 17.68 MB

class Solution:
    def maximum69Number (self, num: int) -> int:
        return int(str(num).replace('6', '9', 1))
