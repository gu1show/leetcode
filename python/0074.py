# Link: https://leetcode.com/problems/search-a-2d-matrix/description/
# The first solution
# Runtime: 57 ms
# Memory: 22.7 MB

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        return self.__can_found_value(matrix, target, 0, len(matrix) * len(matrix[0]) - 1)

    def __can_found_value(self, matrix: List[List[int]], target: int, left: int, right: int) -> bool:
        if left <= right:
            middle = left + (right - left) // 2
            chosen_value = matrix[middle // len(matrix[0])][middle % len(matrix[0])]

            if chosen_value == target: return True
            elif chosen_value > target: return self.__can_found_value(matrix, target, left, right - 1)
            else: return self.__can_found_value(matrix, target, middle + 1, right)
        else: return False

# The second solution
# Runtime: 46 ms
# Memory: 16.87 MB

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        left, right = 0, len(matrix) * len(matrix[0]) - 1
        is_found = False
        while (left <= right) and (not is_found):
            middle = left + (right - left) // 2
            chosen_value = matrix[middle // len(matrix[0])][middle % len(matrix[0])]

            if chosen_value == target: is_found = True
            elif chosen_value > target: right = middle - 1
            else: left = middle + 1

        return is_found
