// Link: https://leetcode.com/problems/minimum-common-value/description/
// Runtime: 61 ms
// Memory: 52.83 MB

class Solution {
public:
  int getCommon(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    int i = 0, j = 0;
    while ((i < static_cast<int>(nums1.size())) &&
           (j < static_cast<int>(nums2.size()))) {
      if (nums1[i] == nums2[j])
        return nums1[i];
      else if (nums1[i] < nums2[j])
        i++;
      else
        j++;
    }

    return -1;
  }
};
