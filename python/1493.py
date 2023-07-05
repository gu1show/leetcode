# Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
# Runtime: 399 ms
# Memory: 19.2 MB

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        left, zeros, longest_subarray = 0, 0, 0
        for right, value in enumerate(nums):
            if value == 0:
                zeros += 1
            
            while zeros > 1:
                if nums[left] == 0:
                    zeros -= 1
                left += 1
            longest_subarray = max(longest_subarray, right - left)
        
        return min(longest_subarray, len(nums) - 1)
