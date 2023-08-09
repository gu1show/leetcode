# Link: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/
# Runtime: 1010 ms
# Memory: 30.89 MB

class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        sorted_nums = nums[:]
        sorted_nums.sort()

        left, right = 0, sorted_nums[-1] - sorted_nums[0]
        while left <= right:
            middle = left + (right - left) // 2

            if self.__get_number_of_pairs(sorted_nums, middle) >= p: right = middle - 1
            else: left = middle + 1
        
        return left
        
    def __get_number_of_pairs(self, sorted_nums: List[int], difference: int) -> int:
        i, number_of_pairs = 0, 0
        while (i < len(sorted_nums) - 1):
            if sorted_nums[i + 1] - sorted_nums[i] <= difference:
                number_of_pairs += 1
                i += 1
            
            i += 1
        
        return number_of_pairs
