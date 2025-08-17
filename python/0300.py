# Link: https://leetcode.com/problems/longest-increasing-subsequence/description/
# Runtime: 1816 ms
# Memory: 17.79 MB


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        length_of_LIS = [1] * len(nums)
        for i in range(len(nums) - 1, -1, -1):
            for j in range(i + 1, len(nums)):
                if nums[i] < nums[j]:
                    length_of_LIS[i] = max(length_of_LIS[i], length_of_LIS[j] + 1)

        return max(length_of_LIS)
