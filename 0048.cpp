// Link: https://leetcode.com/problems/rotate-image/
// Runtime: 3 ms 
// Memory: 7.2 MB

class Solution 
{
public:
    void rotate(std::vector<std::vector<int>>& matrix) 
    {
        for (int i = 0; i < matrix.size(); i++)
            for (int j = i; j < matrix.size(); j++)
                std::swap(matrix[i][j], matrix[j][i]);
        
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix.size() / 2; j++)
                std::swap(matrix[i][j], matrix[i][matrix.size() - 1 - j]);
    }
};
