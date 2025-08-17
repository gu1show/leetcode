# Link: https://leetcode.com/problems/matrix-diagonal-sum/description/
# Runtime: 118 ms
# Memory: 16.6 MB


class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        diagonalSum = 0
        for i in range(len(mat)):
            diagonalSum += mat[i][i] + mat[len(mat) - i - 1][i]

        if len(mat) % 2 == 1:
            diagonalSum -= mat[len(mat) // 2][len(mat) // 2]

        return diagonalSum
