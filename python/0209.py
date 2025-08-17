# Link: https://leetcode.com/problems/minimum-size-subarray-sum/description/
# Runtime: 258 ms
# Memory: 29.1 MB


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        sum, left, minimum_size = 0, 0, len(nums)
        has_correct_sum = False
        for right, value in enumerate(nums):
            sum += value

            while sum >= target:
                minimum_size = min(minimum_size, right - left + 1)
                sum -= nums[left]
                left += 1
                has_correct_sum = True

        if has_correct_sum:
            return minimum_size
        else:
            return 0
