# Link: https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/description/
# Runtime: 0 ms
# Memory: 17.78 MB


class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        max_area, max_almost_diagonal = 0, 0
        for i, dimension in enumerate(dimensions):
            almost_diagonal = dimension[0] ** 2 + dimension[1] ** 2
            if almost_diagonal > max_almost_diagonal:
                max_almost_diagonal = almost_diagonal
                max_area = dimension[0] * dimension[1]
            elif almost_diagonal == max_almost_diagonal:
                max_area = max(max_area, dimension[0] * dimension[1])

        return max_area
