// Link: https://leetcode.com/problems/monotonic-array/description/
// Runtime: 123 ms
// Memory: 96.8 MB

class Solution {
public:
  bool isMonotonic(const std::vector<int> &nums) {
    if (nums.size() < 3)
      return true;

    short direction = 0;
    for (int i = 1; i < static_cast<int>(nums.size()); i++) {
      if ((nums[i - 1] < nums[i]) && (direction == 0))
        direction = 1;
      else if ((nums[i - 1] < nums[i]) && (direction == -1))
        return false;
      else if ((nums[i - 1] > nums[i]) && (direction == 0))
        direction = -1;
      else if ((nums[i - 1] > nums[i]) && (direction == 1))
        return false;
    }

    return true;
  }
};
