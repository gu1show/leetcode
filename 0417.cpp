// Link: https://leetcode.com/problems/pacific-atlantic-water-flow/
// Runtime: 61 ms 
// Memory: 17.5 MB

using vector2dInt = std::vector<std::vector<int>>;
using vector2dBool = std::vector<std::vector<bool>>;

class Solution
{
public:
    vector2dInt pacificAtlantic(const vector2dInt& heights) 
    {
        int n = heights.size(), m = heights[0].size();
        vector2dBool reachingPacificOcean(n, std::vector<bool>(m));
        vector2dBool reachingAtlanticOcean(n, std::vector<bool>(m)); 
        
        for (int i = 0; i < n; i++)
        {
            canReach(heights, reachingPacificOcean, i, 0);
            canReach(heights, reachingAtlanticOcean, i, m - 1);
        }        
              
        for (int i = 0; i < m; i++)
        {            
            canReach(heights, reachingPacificOcean, 0, i);
            canReach(heights, reachingAtlanticOcean, n - 1, i);
        }
        
        vector2dInt result;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if ((reachingPacificOcean[i][j]) && (reachingAtlanticOcean[i][j]))
                    result.push_back({i, j});
        
        return result;
    }
    
private:
    void canReach(const vector2dInt& heights, vector2dBool& reaching, int r, int c)
    {
        reaching[r][c] = true;
        
        if ((r - 1 > -1) && (!reaching[r - 1][c]) && 
            (heights[r - 1][c] >= heights[r][c])) 
            canReach(heights, reaching, r - 1, c); 
        
        if ((r + 1 < heights.size()) && (!reaching[r + 1][c]) && 
            (heights[r + 1][c] >= heights[r][c]))
            canReach(heights, reaching, r + 1, c);
        
        if ((c - 1 > -1) && (!reaching[r][c - 1]) && 
            (heights[r][c - 1] >= heights[r][c]))
            canReach(heights, reaching, r, c - 1);
        
        if ((c + 1 < heights[0].size()) && (!reaching[r][c + 1]) && 
            (heights[r][c + 1] >= heights[r][c]))
            canReach(heights, reaching, r, c + 1);
    }
};
