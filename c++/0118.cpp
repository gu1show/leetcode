// Link: https://leetcode.com/problems/pascals-triangle/
// Runtime: 0 ms
// Memory: 6.3 MB

class Solution {
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> triangle;
    for (int i = 0; i < numRows; i++) {
      std::vector<int> row(i + 1, 1);
      for (int j = 1; j < i; j++)
        row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
      triangle.push_back(row);
    }

    return triangle;
  }
};
