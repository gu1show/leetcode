// Link: https://leetcode.com/problems/transpose-matrix/
// Runtime: 23 ms
// Memory: 10.6 MB

class Solution {
public:
  std::vector<std::vector<int>>
  transpose(const std::vector<std::vector<int>> &matrix) {
    std::vector<std::vector<int>> transposeMatrix(
        matrix[0].size(), std::vector<int>(matrix.size()));

    for (int i = 0; i < matrix.size(); i++)
      for (int j = 0; j < matrix[0].size(); j++)
        transposeMatrix[j][i] = matrix[i][j];

    return transposeMatrix;
  }
};
