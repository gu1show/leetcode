# Link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/
# Runtime: 507 ms
# Memory: 28.68 MB

class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        sorted_piles = piles[:]
        sorted_piles.sort()

        return sum(sorted_piles[len(sorted_piles) // 3::2])
