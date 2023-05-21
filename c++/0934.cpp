// Link: https://leetcode.com/problems/shortest-bridge/description/
// Runtime: 702 ms
// Memory: 25.4 MB

class Solution 
{
public:
    int shortestBridge(const std::vector<std::vector<int>>& grid) 
    {
        int number = 2;
        std::vector<std::vector<int>> gridCopy = grid;
        for (int i = 0; i < static_cast<int>(grid.size()); i++)
            for (int j = 0; j < static_cast<int>(grid[0].size()); j++)
            {
                if (grid[i][j] == 1)
                {
                    setMarks(i, j, number, gridCopy);
                    number++;
                }
            }
        
        int minimumFlip = 10000;
        for (int i = 0; i < static_cast<int>(firstIsland.size()); i++)
            for (int j = 0; j < static_cast<int>(secondIsland.size()); j++)
                minimumFlip = std::min(minimumFlip, 
                                       abs(firstIsland[i].first - secondIsland[j].first) + abs(firstIsland[i].second - secondIsland[j].second) - 1);
        
        return minimumFlip;
    }

private:
    std::vector<std::pair<int, int>> firstIsland, secondIsland;

    void setMarks(int i, int j, int number, std::vector<std::vector<int>>& grid)
    {
        if ((i > -1) && (i < static_cast<int>(grid.size())) &&
        (j > -1) && (j < static_cast<int>(grid[0].size())) && (grid[i][j] == 1))
        {
            grid[i][j] = number;

            if (number == 2) firstIsland.push_back({i, j});
            else secondIsland.push_back({i, j});

            setMarks(i + 1, j, number, grid);
            setMarks(i - 1, j, number, grid);
            setMarks(i, j + 1, number, grid);
            setMarks(i, j - 1, number, grid);
        }
    }
};
