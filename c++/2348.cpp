// Link: https://leetcode.com/problems/number-of-zero-filled-subarrays/description/
// Runtime: 0 ms
// Memory: 111.34 MB

class Solution {
public:
  long long zeroFilledSubarray(const std::vector<int> &nums) {
    long long numberOfSubarrays = 0;
    int streak = 0;
    for (const auto &val : nums) {
      if (val == 0) {
        streak++;
        numberOfSubarrays += streak;
      } else {
        streak = 0;
      }
    }

    return numberOfSubarrays;
  }
};