// Link: https://leetcode.com/problems/number-of-ways-to-split-array/description/
// Runtime: 0 ms
// Memory: 89.32 MB

class Solution {
public:
  int waysToSplitArray(const std::vector<int> &nums) {
    long long leftSum = 0, rightSum = 0;
    for (const auto &val : nums)
      rightSum += val;

    int numberOfWaysToSplitArray = 0;
    for (int i = 0; i < static_cast<int>(nums.size() - 1); i++) {
      leftSum += nums[i];
      rightSum -= nums[i];

      if (leftSum >= rightSum)
        numberOfWaysToSplitArray++;
    }

    return numberOfWaysToSplitArray;
  }
};
