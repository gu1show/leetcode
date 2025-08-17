// Link: https://leetcode.com/problems/sliding-window-maximum/description/
// Runtime: 193 ms
// Memory: 134.66 MB

class Solution {
public:
  std::vector<int> maxSlidingWindow(const std::vector<int> &nums, int k) {
    std::deque<int> potentialMaximums;
    for (int i = 0; i < k; i++) {
      removeRedundantValues(nums, potentialMaximums, nums[i]);

      potentialMaximums.push_back(i);
    }

    std::vector<int> maximums;
    maximums.push_back(nums[potentialMaximums.front()]);
    for (int i = k; i < static_cast<int>(nums.size()); i++) {
      if (potentialMaximums.front() == i - k)
        potentialMaximums.pop_front();
      removeRedundantValues(nums, potentialMaximums, nums[i]);

      potentialMaximums.push_back(i);
      maximums.push_back(nums[potentialMaximums.front()]);
    }

    return maximums;
  }

private:
  void removeRedundantValues(const std::vector<int> &nums,
                             std::deque<int> &potentialMaximums,
                             int currentValue) {
    while ((!potentialMaximums.empty()) &&
           (nums[potentialMaximums.back()] <= currentValue))
      potentialMaximums.pop_back();
  }
};
