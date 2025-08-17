// Link: https://leetcode.com/problems/gas-station/description/
// Runtime: 94 ms
// Memory: 69.5 MB

class Solution {
public:
  int canCompleteCircuit(const std::vector<int> &gas,
                         const std::vector<int> &cost) {
    int totalGas = 0, totalCost = 0;
    for (int i = 0; i < static_cast<int>(gas.size()); i++) {
      totalGas += gas[i];
      totalCost += cost[i];
    }

    if (totalGas < totalCost)
      return -1;

    int startIndex = 0, gasNow = 0;
    for (int i = 0; i < static_cast<int>(gas.size()); i++) {
      if (gasNow < 0) {
        gasNow = 0;
        startIndex = i;
      }

      gasNow += (gas[i] - cost[i]);
    }

    return startIndex;
  }
};
