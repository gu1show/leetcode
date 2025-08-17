# Link: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/
# Runtime: 106 ms
# Memory: 16.77 MB


class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        max_k = -1
        values = set()
        for num in nums:
            if (abs(num) > max_k) and (-num in values):
                max_k = abs(num)
            values.add(num)

        return max_k
