// Link: https://leetcode.com/problems/unique-paths/
// Runtime: 3 ms
// Memory: 6.4 MB

class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        std::vector<std::vector<int>> board(m, std::vector<int>(n));
        
        int i = m - 1, j = n - 1;
        board[i][j] = 1;
        while ((i != 0) || (j != 0))
        {
            j--;
            if (j < 0)
            {
                j = n - 1; 
                i--;
            } 
            
            if (j + 1 != n) board[i][j] = board[i][j + 1];
            if (i + 1 != m) board[i][j] += board[i + 1][j];
        }
        
        return board[0][0];
    }
};
