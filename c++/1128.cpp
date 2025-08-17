// Link: https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/
// Runtime: 4 ms
// Memory: 26.35 MB

class Solution {
public:
  int numEquivDominoPairs(const std::vector<std::vector<int>> &dominoes) {
    std::map<std::pair<int, int>, int> pairFrequency;
    int numberOfEquivalentPairs = 0;
    for (const auto &domino : dominoes) {
      std::pair<int, int> dominoSortedOrder = {};
      if (domino[0] > domino[1])
        dominoSortedOrder = std::make_pair(domino[1], domino[0]);
      else
        dominoSortedOrder = std::make_pair(domino[0], domino[1]);

      int frequency = pairFrequency[dominoSortedOrder];
      if (frequency > 0)
        numberOfEquivalentPairs += frequency;

      pairFrequency[dominoSortedOrder]++;
    }

    return numberOfEquivalentPairs;
  }
};
