# Link: https://leetcode.com/problems/bag-of-tokens/description/
# Runtime: 41 ms
# Memory: 16.77 MB


class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        current_power, sorted_tokens = power, tokens[:]
        sorted_tokens.sort()

        low, high, score, can_step = 0, len(sorted_tokens) - 1, 0, True
        while (low <= high) and (can_step):
            if sorted_tokens[low] <= current_power:
                current_power -= sorted_tokens[low]
                low += 1
                score += 1
            elif (low < high) and (score > 0):
                current_power += sorted_tokens[high]
                high -= 1
                score -= 1
            else:
                can_step = False

        return score
