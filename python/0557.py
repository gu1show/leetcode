# Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
# Runtime: 46 ms
# Memory: 16.68 MB


class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.split()[::-1])[::-1]
