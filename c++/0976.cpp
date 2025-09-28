// Link: https://leetcode.com/problems/largest-perimeter-triangle/
// Runtime: 18 ms
// Memory: 29.91 MB

class Solution {
public:
  int largestPerimeter(const std::vector<int> &nums) {
    auto copyNums = nums;
    std::sort(copyNums.rbegin(), copyNums.rend());
    for (int i = 0; i < static_cast<int>(copyNums.size() - 2); i++) {
      if (copyNums[i] < copyNums[i + 1] + copyNums[i + 2]) {
        return copyNums[i] + copyNums[i + 1] + copyNums[i + 2];
      }
    }

    return 0;
  }
};
