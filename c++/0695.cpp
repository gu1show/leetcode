// Link: https://leetcode.com/problems/max-area-of-island/
// Runtime: 30 ms
// Memory: 23.6 MB

class Solution 
{
public:
    int countArea(const vector<vector<int>>& grid, std::vector<std::vector<bool>>& isSeen, int row, int column)
    {
        if ((row < 0) || (row >= grid.size()) || (column < 0) || (column >= grid[0].size()) || (isSeen[row][column]) || (grid[row][column] == 0)) return 0;
        else
        {
            isSeen[row][column] = true;
            return 1 + countArea(grid, isSeen, row + 1, column) + countArea(grid, isSeen, row - 1, column) + countArea(grid, isSeen, row, column + 1) + countArea(grid, isSeen, row, column - 1);
        }
    }
    
    int maxAreaOfIsland(const vector<vector<int>>& grid) 
    {
        std::vector<std::vector<bool>> isSeen(grid.size(), std::vector<bool>(grid[0].size()));
        int maxSquare = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                maxSquare = std::max(maxSquare, countArea(grid, isSeen, i, j));
        
        return maxSquare;
    }
};
