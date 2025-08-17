// Link: https://leetcode.com/problems/squares-of-a-sorted-array/description/
// Runtime: 11 ms
// Memory: 28.28 MB

class Solution {
public:
  std::vector<int> sortedSquares(const std::vector<int> &nums) {
    std::vector<int> sortedSquaresArray(nums.size());
    int left = 0, right = static_cast<int>(nums.size() - 1);
    for (int i = static_cast<int>(nums.size() - 1); i > -1; i--) {
      if (abs(nums[left]) < abs(nums[right])) {
        sortedSquaresArray[i] = nums[right] * nums[right];
        right--;
      } else {
        sortedSquaresArray[i] = nums[left] * nums[left];
        left++;
      }
    }

    return sortedSquaresArray;
  }
};
