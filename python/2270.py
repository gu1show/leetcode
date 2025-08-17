# Link: https://leetcode.com/problems/number-of-ways-to-split-array/description/
# Runtime: 48 ms
# Memory: 32.34 MB


class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        left_sum, right_sum = 0, sum(nums)

        number_of_ways_to_split_array = 0
        for i in range(len(nums) - 1):
            left_sum += nums[i]
            right_sum -= nums[i]

            if left_sum >= right_sum:
                number_of_ways_to_split_array += 1

        return number_of_ways_to_split_array
