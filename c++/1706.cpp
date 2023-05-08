// Link: https://leetcode.com/problems/where-will-the-ball-fall/
// Runtime: 54 ms
// Memory: 13 MB

class Solution 
{
public:
    std::vector<int> findBall(const std::vector<std::vector<int>>& grid)
    {
        std::vector<int> balls(grid[0].size());
        for (int i = 0; i < static_cast<int>(balls.size()); i++)
        {
            int row = 0, currentColumn = i;
            bool canContinue = true;
            while ((row < grid.size()) && (canContinue)) 
            {
                int nextColumn = currentColumn + grid[row][currentColumn];
                if ((nextColumn < 0) || (nextColumn > grid[0].size() - 1)
                    || (grid[row][currentColumn] != grid[row][nextColumn]))
                {
                    balls[i] = -1;
                    canContinue = false;
                }
                else
                {
                    balls[i] = nextColumn;
                    currentColumn = nextColumn;
                }
                row++;
            }
        }
        
        return balls;
    }
};
