# Link: https://leetcode.com/problems/monotonic-array/description/
# Runtime: 868 ms
# Memory: 30.4 MB


class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return True

        direction = 0
        for i in range(1, len(nums)):
            if (nums[i - 1] < nums[i]) and (direction == 0):
                direction = 1
            elif (nums[i - 1] < nums[i]) and (direction == -1):
                return False
            elif (nums[i - 1] > nums[i]) and (direction == 0):
                direction = -1
            elif (nums[i - 1] > nums[i]) and (direction == 1):
                return False

        return True
