// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// The first solution
// Runtime: 24 ms
// Memory: 10.8 MB

class Solution {
public:
  int minMoves2(const std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    int middleValue = nums[nums.size() / 2], minimumMoves = 0;
    for (int i = 0; i < nums.size(); i++)
      minimumMoves += abs(nums[i] - middleValue);

    return minimumMoves;
  }
};

// The second solution
// Runtime: 11 ms
// Memory: 10.9 MB

class Solution {
public:
  int minMoves2(std::vector<int> &nums) {
    std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());

    int middleValue = nums[nums.size() / 2], minimumMoves = 0;
    for (int i = 0; i < nums.size(); i++)
      minimumMoves += abs(nums[i] - middleValue);

    return minimumMoves;
  }
};
