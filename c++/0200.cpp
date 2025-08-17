// Link: https://leetcode.com/problems/number-of-islands/
// Runtime: 53 ms
// Memory: 12.2 MB

class Solution {
public:
  int numIslands(std::vector<std::vector<char>> &grid) {
    int numberOfIslands = 0;
    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid[0].size(); j++)
        if (grid[i][j] == '1') {
          processIsland(grid, i, j);
          numberOfIslands++;
        }

    return numberOfIslands;
  }

private:
  void processIsland(std::vector<std::vector<char>> &grid, int i, int j) {
    if ((i > -1) && (i < grid.size()) && (j > -1) && (j < grid[0].size()) &&
        (grid[i][j] == '1')) {
      grid[i][j] = '0';

      processIsland(grid, i - 1, j);
      processIsland(grid, i + 1, j);
      processIsland(grid, i, j - 1);
      processIsland(grid, i, j + 1);
    }
  }
};
