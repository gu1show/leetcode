# Link: https://leetcode.com/problems/strange-printer/description/
# Runtime: 1374 ms
# Memory: 16.3 MB


class Solution:
    def strangePrinter(self, s: str) -> int:
        segments_changing = [[len(s)] * len(s) for _ in range(len(s))]
        for length in range(1, len(s) + 1):
            for left in range(len(s) - length + 1):
                right = left + length - 1
                j = -1
                for i in range(left, right):
                    if (s[i] != s[right]) and (j == -1):
                        j = i

                    if j != -1:
                        segments_changing[left][right] = min(
                            segments_changing[left][right],
                            1
                            + segments_changing[j][i]
                            + segments_changing[i + 1][right],
                        )

                if j == -1:
                    segments_changing[left][right] = 0

        return 1 + segments_changing[0][-1]
