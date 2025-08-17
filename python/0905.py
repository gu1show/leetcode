# Link: https://leetcode.com/problems/sort-array-by-parity/description/
# The first solution
# Runtime: 68 ms
# Memory: 17.13 MB


class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        sorted_nums = nums[:]
        left = 0
        for right in range(len(sorted_nums)):
            if sorted_nums[right] % 2 == 0:
                sorted_nums[left], sorted_nums[right] = (
                    sorted_nums[right],
                    sorted_nums[left],
                )
                left += 1

        return sorted_nums


# The second solution
# Runtime: 81 ms
# Memory: 17.05 MB


class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        return [x for x in nums if x % 2 == 0] + [x for x in nums if x % 2 != 0]
