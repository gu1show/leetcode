// Link: https://leetcode.com/problems/running-sum-of-1d-array/
// The first solution
// Runtime: 5 ms
// Memory: 8.5 MB

class Solution {
public:
  std::vector<int> runningSum(std::vector<int> &nums) {
    for (int i = nums.size() - 1; i > -1; i--)
      for (int j = 0; j < i; j++)
        nums[i] += nums[j];

    return nums;
  }
};

// The second solution
// Runtime: 0 ms
// Memory: 8.5 MB

class Solution {
public:
  std::vector<int> runningSum(std::vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++)
      nums[i] += nums[i - 1];

    return nums;
  }
};
