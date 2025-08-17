// Link: https://leetcode.com/problems/toeplitz-matrix/
// Runtime: 40 ms
// Memory: 17.4 MB

class Solution {
public:
  bool isToeplitzMatrix(const std::vector<std::vector<int>> &matrix) {
    for (int i = 0; i < static_cast<int>(matrix.size()); i++)
      for (int j = 0; j < static_cast<int>(matrix[0].size()); j++)
        if ((i > 0) && (j > 0) && (matrix[i][j] != matrix[i - 1][j - 1]))
          return false;

    return true;
  }
};
