// Link: https://leetcode.com/problems/poor-pigs/
// Runtime: 0 ms
// Memory: 6 MB

class Solution {
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    return std::ceil(std::log(buckets) /
                     std::log(minutesToTest / minutesToDie + 1));
  }
};
