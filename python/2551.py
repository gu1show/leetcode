# Link: https://leetcode.com/problems/put-marbles-in-bags/description/
# Runtime: 718 ms
# Memory: 30 MB

class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        pair_weights = [x + y for x, y in pairwise(weights)]
        pair_weights.sort()

        if k == 1:
            return 0
        else:
            return sum(pair_weights[-(k - 1):]) - sum(pair_weights[:(k - 1)])
        