// Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
// The first solution
// Runtime: 412 ms
// Memory: 14.8 MB

class Solution {
public:
  bool searchMatrix(const std::vector<std::vector<int>> &matrix, int target) {
    int i = 0;
    while ((i < matrix.size()) &&
           (!std::binary_search(matrix[i].begin(), matrix[i].end(), target)))
      i++;

    if (i == matrix.size())
      return false;
    else
      return true;
  }
};

// The second solution
// Runtime: 206 ms
// Memory: 14.9 MB

class Solution {
public:
  bool searchMatrix(const std::vector<std::vector<int>> &matrix, int target) {
    int row = 0, column = matrix[0].size() - 1;
    bool isFound = false;
    while ((row < matrix.size()) && (row > -1) && (column < matrix[0].size()) &&
           (column > -1) && (!isFound)) {
      if (matrix[row][column] == target)
        isFound = true;
      else if (matrix[row][column] > target)
        column--;
      else
        row++;
    }

    return isFound;
  }
};
