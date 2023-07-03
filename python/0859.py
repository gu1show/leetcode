# Link: https://leetcode.com/problems/buddy-strings/description/
# Runtime: 51 ms
# Memory: 16.6 MB

class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        
        first_different_symbol_index, second_different_symbol_index = -1, -1
        if s == goal:
            s_set = set()
            for symbol in s:
                if symbol in s_set:
                    return True
                s_set.add(symbol)
        else:
            for index, value in enumerate(s):
                if (s[index] != goal[index]) and (first_different_symbol_index == -1):
                    first_different_symbol_index = index
                elif (s[index] != goal[index]) and (second_different_symbol_index == -1):
                    second_different_symbol_index = index
                elif s[index] != goal[index]:
                    return False
        
        if second_different_symbol_index == -1:
            return False

        return s[first_different_symbol_index] == goal[second_different_symbol_index] and goal[first_different_symbol_index] == s[second_different_symbol_index]
