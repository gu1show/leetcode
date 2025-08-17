// Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
// Runtime: 131 ms
// Memory: 126.4 MB

class Solution {
public:
  std::vector<int> rearrangeArray(const std::vector<int> &nums) {
    std::vector<int> rearrangedArray(nums.size());
    int positiveIndex = 0, negativeIndex = 1;
    for (const auto &val : nums) {
      if (val > 0) {
        rearrangedArray[positiveIndex] = val;
        positiveIndex += 2;
      } else {
        rearrangedArray[negativeIndex] = val;
        negativeIndex += 2;
      }
    }

    return rearrangedArray;
  }
};
