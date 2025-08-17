# Link: https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/
# Runtime: 905 ms
# Memory: 30.21 MB


class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        can_part = [True] + [False] * 2
        for i in range(len(nums)):
            can_part_up_to_position = False
            if (i > 0) and (nums[i] == nums[i - 1]):
                can_part_up_to_position |= can_part[(i - 1) % 3]
            if (i > 1) and (
                (nums[i] == nums[i - 1] == nums[i - 2])
                or (nums[i] == nums[i - 1] + 1 == nums[i - 2] + 2)
            ):
                can_part_up_to_position |= can_part[(i - 2) % 3]

            can_part[(i + 1) % 3] = can_part_up_to_position

        return can_part[len(nums) % 3]
