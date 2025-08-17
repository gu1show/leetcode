// Link: https://leetcode.com/problems/intersection-of-two-arrays/description/
// Runtime: 4 ms
// Memory: 13.22 MB

class Solution {
public:
  std::vector<int> intersection(const std::vector<int> &nums1,
                                const std::vector<int> &nums2) {
    std::unordered_map<int, int> valueAndFrequency;
    for (const auto &val : nums1)
      valueAndFrequency[val]++;

    std::vector<int> intersectionArray;
    for (const auto &val : nums2) {
      if (valueAndFrequency.find(val) != valueAndFrequency.end()) {
        intersectionArray.push_back(val);
        valueAndFrequency.erase(val);
      }
    }

    return intersectionArray;
  }
};
