// Link: https://leetcode.com/problems/number-of-zero-filled-subarrays/description/
// Runtime: 0 ms
// Memory: 29.28 MB

class Solution {
public:
  int areaOfMaxDiagonal(const std::vector<std::vector<int>> &dimensions) {
    int maxArea = 0, maxAlmostDiagonal = 0;
    for (int i = 0; i < static_cast<int>(dimensions.size()); i++) {
      int almostDiagonal = dimensions[i][0] * dimensions[i][0] +
                           dimensions[i][1] * dimensions[i][1];
      if (almostDiagonal > maxAlmostDiagonal) {
        maxAlmostDiagonal = almostDiagonal;
        maxArea = dimensions[i][0] * dimensions[i][1];
      } else if (fabs(almostDiagonal - maxAlmostDiagonal) <
                 std::numeric_limits<double>::epsilon()) {
        maxArea = std::max(maxArea, dimensions[i][0] * dimensions[i][1]);
      }
    }

    return maxArea;
  }
};
