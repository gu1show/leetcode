# Link: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/
# Runtime: 278 ms
# Memory: 16.8 MB


class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        maxSize = 0
        occurances = defaultdict(lambda: 0)
        for right, value in enumerate(answerKey):
            occurances[value] += 1
            if min(occurances["T"], occurances["F"]) <= k:
                maxSize += 1
            else:
                occurances[answerKey[right - maxSize]] -= 1

        return maxSize
