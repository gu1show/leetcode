// Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
// Runtime: 3 ms
// Memory: 5.9 MB

class Solution {
public:
  int numberOfSteps(int num) {
    int steps = 0;
    while (num > 0) {
      if (num % 2 == 0)
        num = num >> 1;
      else
        --num;
      ++steps;
    }
    return steps;
  }
};
