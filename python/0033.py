# Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
# The first solution
# Runtime: 54 ms
# Memory: 16.7 MB


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return self.__get_index_of_target(nums, target, 0, len(nums) - 1)

    def __get_index_of_target(
        self, nums: List[int], target: int, left: int, right: int
    ) -> int:
        if left <= right:
            middle = left + (right - left) // 2

            if nums[middle] == target:
                return middle
            elif nums[middle] < target:
                if (nums[left] <= nums[middle]) or (
                    (nums[left] > nums[middle]) and (nums[left] > target)
                ):
                    return self.__get_index_of_target(nums, target, middle + 1, right)
                else:
                    return self.__get_index_of_target(nums, target, left, middle - 1)
            else:
                if ((nums[left] < nums[middle]) and (nums[left] <= target)) or (
                    (nums[middle] < nums[right]) and (nums[right] > target)
                ):
                    return self.__get_index_of_target(nums, target, left, middle - 1)
                else:
                    return self.__get_index_of_target(nums, target, middle + 1, right)
        else:
            return -1


# The second solution
# Runtime: 48 ms
# Memory: 16.65 MB


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right, index_of_target = 0, len(nums) - 1, -1
        is_found = False
        while (left <= right) and (not is_found):
            middle = left + (right - left) // 2

            if nums[middle] == target:
                index_of_target, is_found = middle, True
            elif nums[middle] < target:
                if (nums[left] <= nums[middle]) or (
                    (nums[left] > nums[middle]) and (nums[left] > target)
                ):
                    left = middle + 1
                else:
                    right = middle - 1
            else:
                if ((nums[left] < nums[middle]) and (nums[left] <= target)) or (
                    (nums[middle] < nums[right]) and (nums[right] > target)
                ):
                    right = middle - 1
                else:
                    left = middle + 1

        return index_of_target
