// Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
// Runtime: 36 ms
// Memory: 36.5 MB

class Solution {
public:
  int longestSubarray(const std::vector<int> &nums) {
    int left = 0, zeros = 0, longestSubarray = 0;
    for (int right = 0; right < static_cast<int>(nums.size()); right++) {
      if (nums[right] == 0)
        zeros++;

      while (zeros > 1) {
        if (nums[left] == 0)
          zeros--;
        left++;
      }

      longestSubarray = std::max(longestSubarray, right - left);
    }

    return std::min(longestSubarray, static_cast<int>(nums.size() - 1));
  }
};
