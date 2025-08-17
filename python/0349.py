# Link: https://leetcode.com/problems/intersection-of-two-arrays/description/
# Runtime: 39 ms
# Memory: 16.8 MB


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list(set(nums1) & set(nums2))
