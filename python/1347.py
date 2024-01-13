# Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/
# Runtime: 101 ms
# Memory: 17.84 MB

class Solution:
    def minSteps(self, s: str, t: str) -> int:
        return (Counter(s) - Counter(t)).total()
