# Link: https://leetcode.com/problems/first-unique-character-in-a-string/description/
# Runtime: 77 ms
# Memory: 16.75 MB


class Solution:
    def firstUniqChar(self, s: str) -> int:
        symbol_and_frequency = Counter(s)
        for index, symbol in enumerate(s):
            if symbol_and_frequency[symbol] == 1:
                return index

        return -1
