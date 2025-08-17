# Link: https://leetcode.com/problems/construct-k-palindrome-strings/description/
# Runtime: 20 ms
# Memory: 18.15 MB


class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if len(s) < k:
            return False
        elif len(s) == k:
            return True

        pairs = Counter(s).most_common()
        print
        number_of_odds = 0
        for pair in pairs:
            if pair[1] % 2:
                number_of_odds += 1

        return number_of_odds <= k
