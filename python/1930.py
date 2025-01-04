# Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/
# Runtime: 549 ms
# Memory: 18.12 MB

class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        first_occurrance_index, last_occurrance_index = [-1] * 26, [-1] * 26
        for index, symbol in enumerate(s):
            if first_occurrance_index[ord(symbol) - ord('a')] == -1:
                first_occurrance_index[ord(symbol) - ord('a')] = index
            
            last_occurrance_index[ord(symbol) - ord('a')] = index
        
        number_of_palindromes_length3 = 0
        for i in range(26):
            if first_occurrance_index[i] != last_occurrance_index[i]:
                chars_between = set()
                for j in range(first_occurrance_index[i] + 1, last_occurrance_index[i]):
                    chars_between.add(s[j])

                number_of_palindromes_length3 += len(chars_between)
        
        return number_of_palindromes_length3
