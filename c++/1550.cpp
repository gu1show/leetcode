// Link: https://leetcode.com/problems/three-consecutive-odds/description/
// Runtime: 0 ms
// Memory: 11.81 MB

class Solution {
public:
  bool threeConsecutiveOdds(const std::vector<int> &arr) {
    if (arr.size() < 3)
      return false;

    bool isTheFirstOdd = arr[0] % 2 == 1, isTheSecondOdd = arr[1] % 2 == 1,
         isTheThirdIOdd = arr[2] % 2 == 1;
    for (int i = 3; i < static_cast<int>(arr.size()); i++) {
      if (isTheFirstOdd && isTheSecondOdd && isTheThirdIOdd)
        return true;

      isTheFirstOdd = isTheSecondOdd;
      isTheSecondOdd = isTheThirdIOdd;
      isTheThirdIOdd = arr[i] % 2 == 1;
    }

    return isTheFirstOdd && isTheSecondOdd && isTheThirdIOdd;
  }
};
