# Link: https://leetcode.com/problems/set-mismatch/description/
# Runtime: 166 ms
# Memory: 18.56 MB


class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        expected_sum = len(nums) * (len(nums) + 1) // 2
        actual_sum = sum(nums)

        different_numbers = set()
        duplicate = 0
        i, is_found = 0, False
        while (i < len(nums)) and (not is_found):
            if nums[i] in different_numbers:
                duplicate = nums[i]
                is_found = True

            different_numbers.add(nums[i])

            i += 1

        return [duplicate, expected_sum - (actual_sum - duplicate)]
