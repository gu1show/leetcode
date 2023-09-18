# Link: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
# Runtime: 98 ms
# Memory: 16.8 MB

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        frequency_and_numbers_of_rows = [(sum(value), index) for index, value in enumerate(mat)]
        frequency_and_numbers_of_rows.sort(key=lambda x: (x[0], x[1]))

        return [value[1] for value in frequency_and_numbers_of_rows[:k]]
