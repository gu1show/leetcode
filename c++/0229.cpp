// Link: https://leetcode.com/problems/majority-element-ii/description/
// Runtime: 7 ms
// Memory: 16.23 MB

class Solution {
public:
  std::vector<int> majorityElement(const std::vector<int> &nums) {
    int candidate1 = 0, candidate2 = 1, count1 = 0, count2 = 0;
    std::vector<int> majorityElements;
    for (const auto &val : nums) {
      if (val == candidate1)
        count1++;
      else if (val == candidate2)
        count2++;
      else if (count1 == 0) {
        candidate1 = val;
        count1 = 1;
      } else if (count2 == 0) {
        candidate2 = val;
        count2 = 1;
      } else {
        count1--;
        count2--;
      }
    }

    if (std::count(nums.begin(), nums.end(), candidate1) > nums.size() / 3.0)
      majorityElements.push_back(candidate1);
    if (std::count(nums.begin(), nums.end(), candidate2) > nums.size() / 3.0)
      majorityElements.push_back(candidate2);

    return majorityElements;
  }
};
