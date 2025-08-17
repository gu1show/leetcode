# Link: https://leetcode.com/problems/repeated-substring-pattern/description/
# Runtime: 41 ms
# Memory: 16.48 MB


class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        double_string = s + s
        if s in double_string[1:-1]:
            return True
        else:
            return False
