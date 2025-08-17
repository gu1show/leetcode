// Link: https://leetcode.com/problems/matchsticks-to-square/
// Runtime: 860 ms
// Memory: 10.1 MB

class Solution {
public:
  bool makesquare(std::vector<int> &matchsticks) {
    if (matchsticks.size() < 4)
      return false;
    else {
      int sum = 0;
      for (const int &val : matchsticks)
        sum += val;

      bool canMakeSquare = false;
      if (sum % 4 == 0) {
        std::vector<int> sides(4);
        std::sort(matchsticks.rbegin(), matchsticks.rend());
        canMakeSquare = isSideFinded(matchsticks, sides, 0, sum / 4);
      }

      return canMakeSquare;
    }
  }

private:
  bool isSideFinded(const std::vector<int> &matchsticks,
                    std::vector<int> &sides, int index, int correctSide) {
    if (index == matchsticks.size())
      return sides[0] == sides[1] && sides[1] == sides[2] &&
             sides[2] == correctSide;

    for (short i = 0; i < 4; i++)
      if (sides[i] + matchsticks[index] <= correctSide) {
        sides[i] += matchsticks[index];
        if (isSideFinded(matchsticks, sides, index + 1, correctSide))
          return true;
        sides[i] -= matchsticks[index];
      }

    return false;
  }
};
