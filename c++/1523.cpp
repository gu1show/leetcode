// Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/
// Runtime: 0 ms
// Memory: 6.1 MB

class Solution {
public:
  int countOdds(int low, int high) {
    if ((low % 2 == 0) && (high % 2 == 0))
      return (high - low) / 2;
    else
      return (high - low) / 2 + 1;
  }
};
