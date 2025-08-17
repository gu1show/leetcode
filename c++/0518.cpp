// Link: https://leetcode.com/problems/coin-change-ii/description/
// Runtime: 39 ms
// Memory: 18.73 MB

class Solution {
public:
  int change(int amount, const std::vector<int> &coins) {
    std::vector<std::vector<int>> numberOfCombinations(
        coins.size() + 1, std::vector<int>(amount + 1));
    for (int i = 0; i < static_cast<int>(coins.size()); i++)
      numberOfCombinations[i][0] = 1;

    for (int i = static_cast<int>(coins.size()) - 1; i >= 0; i--)
      for (int j = 1; j <= amount; j++) {
        if (coins[i] > j)
          numberOfCombinations[i][j] = numberOfCombinations[i + 1][j];
        else
          numberOfCombinations[i][j] = numberOfCombinations[i + 1][j] +
                                       numberOfCombinations[i][j - coins[i]];
      }

    return numberOfCombinations[0][amount];
  }
};
