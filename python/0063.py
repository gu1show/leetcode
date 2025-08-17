# Link: https://leetcode.com/problems/unique-paths-ii/description/
# Runtime: 47 ms
# Memory: 16.45 MB


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        paths = [([0] * len(obstacleGrid[0])) for _ in range(len(obstacleGrid))]
        if obstacleGrid[len(obstacleGrid) - 1][len(obstacleGrid[0]) - 1] == 0:
            paths[len(obstacleGrid) - 1][len(obstacleGrid[0]) - 1] = 1

        for i in range(len(paths) - 1, -1, -1):
            for j in range(len(paths[0]) - 1, -1, -1):
                if (obstacleGrid[i][j] == 0) and (i != len(paths) - 1):
                    paths[i][j] += paths[i + 1][j]
                if (obstacleGrid[i][j] == 0) and (j != len(paths[0]) - 1):
                    paths[i][j] += paths[i][j + 1]

        return paths[0][0]
