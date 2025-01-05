# Link: https://leetcode.com/problems/shifting-letters-ii/description/
# Runtime: 61 ms
# Memory: 41.31 MB

class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        differences = [0] * len(s)
        for shift in shifts:
            if shift[2] == 0:
                differences[shift[0]] -= 1
                if shift[1] + 1 < len(s):
                    differences[shift[1] + 1] += 1
            else:
                differences[shift[0]] += 1
                if shift[1] + 1 < len(s):
                    differences[shift[1] + 1] -= 1
        
        shifted_letters, number_of_shifts = list(s), 0
        for i in range(len(s)):
            number_of_shifts = (number_of_shifts + differences[i]) % 26
            if number_of_shifts < 0:
                number_of_shifts += 26
            
            shifted_letters[i] = chr(ord('a') + (ord(s[i]) - ord('a') + number_of_shifts) % 26)
        
        return ''.join(shifted_letters)
