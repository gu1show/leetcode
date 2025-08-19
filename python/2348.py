# Link: https://leetcode.com/problems/number-of-zero-filled-subarrays/description/
# Runtime: 24 ms
# Memory: 28.26 MB


class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        number_of_subarrays, streak = 0, 0
        for val in nums:
            if not val:
                streak += 1
                number_of_subarrays += streak
            else:
                streak = 0

        return number_of_subarrays
