// Link: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/
// Runtime: 106 ms
// Memory: 83.53 MB

class Solution {
public:
  int minimizeMax(const std::vector<int> &nums, int p) {
    std::vector<int> sortedNums = nums;
    std::sort(sortedNums.begin(), sortedNums.end());

    int left = 0, right = sortedNums[sortedNums.size() - 1] - sortedNums[0];
    while (left <= right) {
      int middle = left + (right - left) / 2;

      if (getNumberOfPairs(sortedNums, middle) >= p)
        right = middle - 1;
      else
        left = middle + 1;
    }

    return left;
  }

private:
  int getNumberOfPairs(const std::vector<int> &sortedNums, int difference) {
    int i = 0, numberOfPairs = 0;
    while (i < static_cast<int>(sortedNums.size()) - 1) {
      if (sortedNums[i + 1] - sortedNums[i] <= difference) {
        numberOfPairs++;
        i++;
      }

      i++;
    }

    return numberOfPairs;
  }
};
