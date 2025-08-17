# Link: https://leetcode.com/problems/solving-questions-with-brainpower/description/
# Runtime: 1674 ms
# Memory: 62.4 MB


class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        numberOfQuestions = len(questions)
        ways = [0] * (numberOfQuestions + 1)
        for i in range(numberOfQuestions - 1, -1, -1):
            point, brainpower = questions[i]

            nextPosition = min(numberOfQuestions, i + brainpower + 1)
            ways[i] = max(ways[i + 1], point + ways[nextPosition])

        return ways[0]
