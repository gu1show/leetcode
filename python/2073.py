# Link: https://leetcode.com/problems/time-needed-to-buy-tickets/description/
# Runtime: 38 ms
# Memory: 16.56 MB


class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        total_time = 0
        for i, ticket in enumerate(tickets):
            if i <= k:
                total_time += min(ticket, tickets[k])
            else:
                total_time += min(ticket, tickets[k] - 1)

        return total_time
