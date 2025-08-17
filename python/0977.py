# Link: https://leetcode.com/problems/squares-of-a-sorted-array/description/
# Runtime: 145 ms
# Memory: 18.89 MB


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        sorted_squares_array = nums[:]
        left, right = 0, len(nums) - 1
        for i in range(len(nums) - 1, -1, -1):
            if abs(nums[left]) < abs(nums[right]):
                sorted_squares_array[i] = nums[right] * nums[right]
                right -= 1
            else:
                sorted_squares_array[i] = nums[left] * nums[left]
                left += 1

        return sorted_squares_array
