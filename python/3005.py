# Link: https://leetcode.com/problems/count-elements-with-maximum-frequency/description/
# Runtime: 51 ms
# Memory: 16.70 MB


class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        element_and_frequency = Counter(nums).most_common()
        max_frequency, i = element_and_frequency[0][1], 1
        while (i < len(element_and_frequency)) and element_and_frequency[i][
            1
        ] == element_and_frequency[i - 1][1]:
            max_frequency += element_and_frequency[i][1]
            i += 1

        return max_frequency
