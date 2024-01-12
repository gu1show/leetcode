# Link: https://leetcode.com/problems/determine-if-string-halves-are-alike/description/
# Runtime: 37 ms
# Memory: 17.33 MB

class Solution:
    vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']

    def halvesAreAlike(self, s: str) -> bool:
        return self.__get_number_of_vowels(s[:len(s) // 2]) == self.__get_number_of_vowels(s[len(s) // 2:])
    
    def __get_number_of_vowels(self, part_of_word):
        number_of_vowels = 0
        for symbol in part_of_word:
            if symbol in self.vowels:
                number_of_vowels += 1
        
        return number_of_vowels
