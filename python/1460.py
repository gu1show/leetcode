# Link: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/
# Runtime: 69 ms
# Memory: 16.82 MB

class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        return Counter(target) == Counter(arr)
