// Link: https://leetcode.com/problems/set-mismatch/description/
// Runtime: 36 ms
// Memory: 32.22 MB

class Solution {
public:
  std::vector<int> findErrorNums(const std::vector<int> &nums) {
    int expectedSum = nums.size() * (nums.size() + 1) / 2;
    int actualSum = std::reduce(nums.begin(), nums.end());

    std::unordered_set<int> differentNumbers;
    int i = 0, duplicate = 0;
    bool isFound = false;
    while ((i < static_cast<int>(nums.size())) && (!isFound)) {
      if (differentNumbers.contains(nums[i])) {
        duplicate = nums[i];
        isFound = true;
      }

      differentNumbers.insert(nums[i]);

      i++;
    }

    return {duplicate, expectedSum - (actualSum - duplicate)};
  }
};
