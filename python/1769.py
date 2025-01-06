# Link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/
# Runtime: 11 ms
# Memory: 17.87 MB

class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        balls_on_the_left, balls_on_the_right = 0, 0
        steps_from_the_left, steps_from_the_right = 0, 0
        minimum_operations = [0] * len(boxes)
        for index, value in enumerate(boxes):
            minimum_operations[index] += steps_from_the_left
            if value == '1':
                balls_on_the_left += 1
            steps_from_the_left += balls_on_the_left

            minimum_operations[-index-1] += steps_from_the_right
            if boxes[-index-1] == '1':
                balls_on_the_right += 1
            steps_from_the_right += balls_on_the_right

        return minimum_operations
