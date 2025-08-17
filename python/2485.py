# Link: https://leetcode.com/problems/find-the-pivot-integer/description/
# Runtime: 34 ms
# Memory: 16.34 MB


class Solution:
    def pivotInteger(self, n: int) -> int:
        sum_from_1_to_n = n * (n + 1) // 2
        potential_pivot = int(sqrt(sum_from_1_to_n))

        if potential_pivot * potential_pivot == sum_from_1_to_n:
            return potential_pivot
        else:
            return -1
