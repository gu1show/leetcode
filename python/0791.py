# Link: https://leetcode.com/problems/custom-sort-string/description/
# Runtime: 37 ms
# Memory: 16.59 MB

class Solution:
    def customSortString(self, order: str, s: str) -> str:
        character_and_frequency = Counter(s)
        sorted_string = ''
        for symbol in order:
            if character_and_frequency[symbol] > 0:
                sorted_string += symbol * character_and_frequency[symbol]
                character_and_frequency[symbol] = 0
        
        for symbol in character_and_frequency:
            sorted_string += symbol * character_and_frequency[symbol]
        
        return sorted_string
