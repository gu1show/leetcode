# Link: https://leetcode.com/problems/maximum-odd-binary-number/description/
# Runtime: 26 ms
# Memory: 16.56 MB


class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        number_of_ones = s.count("1")

        return "1" * (number_of_ones - 1) + "0" * (len(s) - number_of_ones) + "1"
