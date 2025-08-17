// Link: https://leetcode.com/problems/climbing-stairs/description/
// Runtime: 0 ms
// Memory: 6.47 MB

class Solution {
public:
  int climbStairs(int n) {
    long long oneBefore = 1, twoBefore = 1;
    for (int i = 0; i < n; i++) {
      long long temp = oneBefore;
      oneBefore += twoBefore;
      twoBefore = temp;
    }

    return twoBefore;
  }
};
