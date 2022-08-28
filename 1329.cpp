// Link: https://leetcode.com/problems/sort-the-matrix-diagonally/
// Runtime: 19 ms 
// Memory: 8.7 MB

class Solution 
{
public:
    std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat) 
    {
        std::vector<int> temp;
        
        for (int i = 0; i < mat.size() - 1; i++)
        {
            temp.clear();
            for (int j = 0, k = i; j < mat[0].size() && k < mat.size(); j++, k++)
                temp.push_back(mat[k][j]);            
            std::sort(temp.begin(), temp.end());
            for (int j = 0, k = i; j < mat[0].size() && k < mat.size(); j++, k++)
                mat[k][j] = temp[j];            
        }
        
        for (int i = 1; i < mat[0].size() - 1; i++)
        {
            temp.clear();
            for (int j = 0, k = i; j < mat.size() && k < mat[0].size(); j++, k++)
                temp.push_back(mat[j][k]);            
            std::sort(temp.begin(), temp.end());
            for (int j = 0, k = i; j < mat.size() && k < mat[0].size(); j++, k++)
                mat[j][k] = temp[j];            
        }
        
        return mat;
    }
};
