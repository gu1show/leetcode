// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/
// Runtime: 82 ms
// Memory: 47.3 MB

class Solution {
public:
  int findKthLargest(const std::vector<int> &nums, int k) {
    std::priority_queue<int> sortedElements{std::less<int>(), nums};
    int i = 0;
    while (i < k - 1) {
      sortedElements.pop();
      i++;
    }

    return sortedElements.top();
  }
};
