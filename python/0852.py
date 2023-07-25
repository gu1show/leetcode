# Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
# Runtime: 595 ms
# Memory: 30.27 MB

class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        left, right = 0, len(arr) - 1
        while left < right:
            middle = left + (right - left) // 2
            if arr[middle] > arr[middle + 1]: right = middle
            else: left = middle + 1
        
        return left
