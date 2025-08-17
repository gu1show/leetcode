// Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Runtime: 176 ms
// Memory: 53.7 MB

class Solution {
public:
  int longestConsecutive(const std::vector<int> &nums) {
    if (nums.empty())
      return 0;
    else {
      std::map<int, int> values;

      for (const int &value : nums)
        values.insert({value, 1});

      std::vector<int> keys;
      for (const auto &[key, value] : values)
        keys.push_back(key);

      int longestSequence = 1, sequence = 1;
      for (int i = 1; i < keys.size(); i++) {
        if (keys[i - 1] + 1 == keys[i])
          sequence++;
        else {
          if (longestSequence < sequence)
            longestSequence = sequence;
          sequence = 1;
        }
      }

      if (longestSequence < sequence)
        longestSequence = sequence;
      return longestSequence;
    }
  }
};
