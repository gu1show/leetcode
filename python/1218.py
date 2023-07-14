# Link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/
# Runtime: 524 ms
# Memory: 30 MB

class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        length_of_subsequence_ended_by_value = defaultdict(lambda: 0)
        for val in arr:
            length_of_subsequence_ended_by_value[val] = length_of_subsequence_ended_by_value[val - difference] + 1

        return max(length_of_subsequence_ended_by_value.values())
