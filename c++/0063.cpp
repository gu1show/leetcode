// Link: https://leetcode.com/problems/unique-paths-ii/
// Runtime: 0 ms
// Memory: 7.5 MB

class Solution {
public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (obstacleGrid[i][j] == 1)
          obstacleGrid[i][j] = -1;

    if ((obstacleGrid[m - 1][n - 1] == 0) && (obstacleGrid[0][0] == 0)) {
      obstacleGrid[0][0] = 1;

      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
          if (obstacleGrid[i][j] != -1) {
            if ((i - 1 > -1) && (obstacleGrid[i - 1][j] != -1))
              obstacleGrid[i][j] += obstacleGrid[i - 1][j];
            if ((j - 1 > -1) && (obstacleGrid[i][j - 1] != -1))
              obstacleGrid[i][j] += obstacleGrid[i][j - 1];
          }
    } else
      obstacleGrid[m - 1][n - 1] = 0;

    return obstacleGrid[m - 1][n - 1];
  }
};
