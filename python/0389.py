# Link: https://leetcode.com/problems/find-the-difference/description/
# Runtime: 42 ms
# Memory: 16.2 MB

class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        for letter in t:
            if s.count(letter) != t.count(letter):
                return letter

        return ' '
