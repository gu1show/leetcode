# Link: https://leetcode.com/problems/largest-perimeter-triangle/description/
# Runtime: 7 ms
# Memory: 18.69 MB

class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        copy_nums = nums[:]
        copy_nums.sort(reverse=True)
        for i in range(len(copy_nums) - 2):
            if copy_nums[i] < copy_nums[i + 1] + copy_nums[i + 2]:
                return copy_nums[i] + copy_nums[i + 1] + copy_nums[i + 2]

        return 0
