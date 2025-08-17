# Link: https://leetcode.com/problems/majority-element-ii/description/
# Runtime: 102 ms
# Memory: 17.77 MB


class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        candidate1, candidate2, count1, count2 = 0, 1, 0, 0
        for val in nums:
            if val == candidate1:
                count1 += 1
            elif val == candidate2:
                count2 += 1
            elif count1 == 0:
                candidate1, count1 = val, 1
            elif count2 == 0:
                candidate2, count2 = val, 1
            else:
                count1 -= 1
                count2 -= 1

        return [
            num for num in (candidate1, candidate2) if nums.count(num) > len(nums) // 3
        ]
