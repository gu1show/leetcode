# Link: https://leetcode.com/problems/reverse-prefix-of-word/description/
# Runtime: 31 ms
# Memory: 16.55 MB

class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        index_of_ch = word.find(ch)
        if index_of_ch != -1:
            return word[index_of_ch::-1] + word[index_of_ch+1:]

        return word
