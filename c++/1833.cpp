// Link: https://leetcode.com/problems/maximum-ice-cream-bars/description/
// Runtime: 199 ms
// Memory: 79.9 MB

class Solution {
public:
  int maxIceCream(std::vector<int> costs, int coins) {
    std::sort(costs.begin(), costs.end());

    int i = 0, corns = 0;
    while ((i < static_cast<int>(costs.size())) && (coins >= costs[i])) {
      coins -= costs[i];
      corns++;
      i++;
    }

    return corns;
  }
};
