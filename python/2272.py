# Link: https://leetcode.com/problems/substring-with-largest-variance/description/
# Runtime: 2907 ms
# Memory: 16.3 MB


class Solution:
    def largestVariance(self, s: str) -> int:
        counter = Counter(s)
        largest_variance = 0
        for major, minor in itertools.permutations(counter, 2):
            major_count, minor_count, rest_minor = 0, 0, counter[minor]
            for symbol in s:
                if (symbol == major) or (symbol == minor):
                    if major == symbol:
                        major_count += 1
                    elif minor == symbol:
                        minor_count += 1
                        rest_minor -= 1

                    if minor_count > 0:
                        largest_variance = max(
                            largest_variance, major_count - minor_count
                        )

                    if (major_count < minor_count) and (rest_minor > 0):
                        major_count, minor_count = 0, 0

        return largest_variance
