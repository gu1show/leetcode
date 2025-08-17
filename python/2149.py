# Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
# Runtime: 1010 ms
# Memory: 47.19 MB


class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        rearranged_array = [0] * len(nums)
        positive_index, negative_index = 0, 1
        for val in nums:
            if val > 0:
                rearranged_array[positive_index] = val
                positive_index += 2
            else:
                rearranged_array[negative_index] = val
                negative_index += 2

        return rearranged_array
