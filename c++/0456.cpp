// Link: https://leetcode.com/problems/132-pattern/
// Runtime: 85 ms
// Memory: 38.2 MB

class Solution {
public:
  bool find132pattern(const std::vector<int> &nums) {
    int thirdElement = INT_MIN;

    int i = nums.size() - 1;
    bool isFound = false;
    while ((i > -1) && (!isFound)) {
      if ((nums[i] < thirdElement))
        isFound = true;
      while ((!pattern.empty()) && (pattern.top() < nums[i])) {
        thirdElement = pattern.top();
        pattern.pop();
      }
      pattern.push(nums[i]);

      i--;
    }
    return isFound;
  }

private:
  std::stack<int> pattern;
};
