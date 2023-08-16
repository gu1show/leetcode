# Link: https://leetcode.com/problems/sliding-window-maximum/description/
# Runtime: 1334 ms
# Memory: 33.38 MB

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        potential_maximums = deque()
        for i in range(k):
            self.__remove_redundant_values(nums, potential_maximums, nums[i])
            potential_maximums.append(i)
        
        maximums = []
        maximums.append(nums[potential_maximums[0]])
        for i in range(k, len(nums)):
            if potential_maximums[0] == i - k: potential_maximums.popleft()
            self.__remove_redundant_values(nums, potential_maximums, nums[i])

            potential_maximums.append(i)
            maximums.append(nums[potential_maximums[0]])

        return maximums
    
    def __remove_redundant_values(self, nums: List[int], potential_maximums: Deque[int], current_value: int) -> None:
        while (len(potential_maximums) > 0) and (nums[potential_maximums[-1]] <= current_value):
                potential_maximums.pop()
