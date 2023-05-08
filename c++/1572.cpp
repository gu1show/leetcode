// Link: https://leetcode.com/problems/matrix-diagonal-sum/description/
// Runtime: 11 ms
// Memory: 11.1 MB

class Solution 
{
public:
    int diagonalSum(const std::vector<std::vector<int>>& mat) 
    {
        int sum = 0;
        for (int i = 0; i < static_cast<int>(mat.size()); i++)
            sum += mat[i][i] + mat[mat.size() - i - 1][i];

        if (mat.size() % 2 == 1) sum -= mat[mat.size() / 2][mat.size() / 2];

        return sum;
    }
};
