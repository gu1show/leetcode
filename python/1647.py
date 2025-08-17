# Link: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/
# Runtime: 102 ms
# Memory: 17.16 MB


class Solution:
    def minDeletions(self, s: str) -> int:
        char_frequency = collections.Counter(s)
        number_of_deletions = 0
        frequencies_after_deletion = set()
        for _, frequency in char_frequency.items():
            while frequency in frequencies_after_deletion and frequency > 0:
                frequency -= 1
                number_of_deletions += 1
            frequencies_after_deletion.add(frequency)

        return number_of_deletions
