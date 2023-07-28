# Link: https://leetcode.com/problems/minimum-size-subarray-sum/description/
# Runtime: 34 ms
# Memory: 16.27 MB

class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        scores = nums[:]
        for difference in range(1, len(nums)):
            for left in range(len(nums) - difference):
                scores[left] = max(nums[left] - scores[left + 1], nums[left + difference] - scores[left])
        
        return scores[0] >= 0
