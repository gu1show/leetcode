# Link: https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/
# Runtime: 11 ms
# Memory: 24.13 MB


class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        pair_frequency = {}
        number_of_equivalent_pairs = 0
        for domino in dominoes:
            domino_sorted_order = ()
            if domino[0] < domino[1]:
                domino_sorted_order = (domino[0], domino[1])
            else:
                domino_sorted_order = (domino[1], domino[0])

            frequency = pair_frequency.get(domino_sorted_order)
            if frequency:
                number_of_equivalent_pairs += frequency
                pair_frequency.update({domino_sorted_order: frequency + 1})
            else:
                pair_frequency.update({domino_sorted_order: 1})

        return number_of_equivalent_pairs
