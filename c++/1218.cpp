// Link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/
// Runtime: 151 ms
// Memory: 56.52 MB

class Solution {
public:
  int longestSubsequence(const std::vector<int> &arr, int difference) {
    int maxSubsequence = 1;
    std::unordered_map<int, int> lengthOfSubsequenceEndedByValue;
    for (const auto &val : arr) {
      lengthOfSubsequenceEndedByValue[val] =
          lengthOfSubsequenceEndedByValue[val - difference] + 1;
      maxSubsequence =
          std::max(maxSubsequence, lengthOfSubsequenceEndedByValue[val]);
    }

    return maxSubsequence;
  }
};
