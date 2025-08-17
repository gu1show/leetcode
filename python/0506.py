# Link: https://leetcode.com/problems/relative-ranks/description/
# Runtime: 72 ms
# Memory: 17.94 MB


class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        sorted_scores = []
        for index, result in enumerate(score):
            sorted_scores.append((-result, index))

        heapq.heapify(sorted_scores)

        ranks = [0] * len(score)
        place = 1
        while sorted_scores:
            original_index = heapq.heappop(sorted_scores)[1]
            if place == 1:
                ranks[original_index] = "Gold Medal"
            elif place == 2:
                ranks[original_index] = "Silver Medal"
            elif place == 3:
                ranks[original_index] = "Bronze Medal"
            else:
                ranks[original_index] = str(place)

            place += 1

        return ranks
