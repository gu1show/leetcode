# Link: https://leetcode.com/problems/number-of-good-pairs/description/
# Runtime: 38 ms
# Memory: 16.29 MB


class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        value_and_frequency = defaultdict(lambda: 0)
        number_of_good_pairs = 0
        for value in nums:
            number_of_good_pairs += value_and_frequency[value]
            value_and_frequency[value] += 1

        return number_of_good_pairs
