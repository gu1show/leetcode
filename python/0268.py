# Link: https://leetcode.com/problems/missing-number/description/
# Runtime: 109 ms
# Memory: 17.81 MB

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        sum_of_array = len(nums) * (len(nums) + 1) // 2
        for num in nums:
            sum_of_array -= num
        
        return sum_of_array
