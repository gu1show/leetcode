# Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/
# Runtime: 522 ms
# Memory: 31.46 MB


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        values_and_frequency = Counter(nums)
        min_number_of_operations = 0
        for value in values_and_frequency.values():
            if value == 1:
                return -1
            elif value % 3 == 0:
                min_number_of_operations += value // 3
            else:
                min_number_of_operations += value // 3 + 1

        return min_number_of_operations
