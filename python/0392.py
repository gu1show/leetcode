# Link: https://leetcode.com/problems/is-subsequence/description/
# Runtime: 34 ms
# Memory: 16.2 MB


class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) == 0:
            return True
        elif len(s) > len(t):
            return False

        i, j = 0, 0
        while j < len(t):
            if s[i] == t[j]:
                i += 1
            j += 1

            if i == len(s):
                return True

        return False
