# Link: https://leetcode.com/problems/word-break/description/
# Runtime: 51 ms
# Memory: 16.45 MB

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        ending = [False] * (len(s) + 1)
        ending[0] = True

        for i in range(1, len(s) + 1):
            j, is_found = 0, False
            while (j < i) and (not is_found):
                if (ending[j]) and (s[j:i] in wordDict):
                    ending[i], is_found = True, True
                j += 1
        
        return ending[-1]
