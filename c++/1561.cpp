// Link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/
// Runtime: 98 ms
// Memory: 56.28 MB

class Solution {
public:
  int maxCoins(const std::vector<int> &piles) {
    std::vector<int> sortedPiles = piles;
    std::sort(sortedPiles.begin(), sortedPiles.end());

    int maxCoins = 0;
    for (int i = static_cast<int>(sortedPiles.size()) / 3;
         i < static_cast<int>(sortedPiles.size()); i += 2)
      maxCoins += sortedPiles[i];

    return maxCoins;
  }
};
