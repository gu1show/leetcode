# Link: https://leetcode.com/problems/maximum-length-of-pair-chain/description/
# Runtime: 189 ms
# Memory: 16.96 MB


class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        sorted_pairs = pairs[:]
        sorted_pairs.sort(key=lambda pair: pair[1])

        length_of_chain, current_right_border = 1, sorted_pairs[0][1]
        for i in range(1, len(sorted_pairs)):
            if current_right_border < sorted_pairs[i][0]:
                length_of_chain += 1
                current_right_border = sorted_pairs[i][1]

        return length_of_chain
