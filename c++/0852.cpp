// Link:
// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
// Runtime: 111 ms
// Memory: 59.54 MB

class Solution {
public:
  int peakIndexInMountainArray(const std::vector<int> &arr) {
    int left = 0, right = static_cast<int>(arr.size()) - 1, middle = 0;
    while (left < right) {
      middle = left + (right - left) / 2;
      if (arr[middle] > arr[middle + 1])
        right = middle;
      else
        left = middle + 1;
    }

    return left;
  }
};
