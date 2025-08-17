// Link: https://leetcode.com/problems/relative-ranks/description/
// Runtime: 0 ms
// Memory: 13.75 MB

class Solution {
public:
  std::vector<std::string> findRelativeRanks(const std::vector<int> &score) {
    std::priority_queue<std::pair<int, int>> sortedScores;
    for (int i = 0; i < static_cast<int>(score.size()); i++)
      sortedScores.push({score[i], i});

    std::vector<std::string> ranks(score.size());
    int place = 1;
    while (!sortedScores.empty()) {
      int originalIndex = sortedScores.top().second;
      if (place == 1)
        ranks[originalIndex] = "Gold Medal";
      else if (place == 2)
        ranks[originalIndex] = "Silver Medal";
      else if (place == 3)
        ranks[originalIndex] = "Bronze Medal";
      else
        ranks[originalIndex] = std::to_string(place);

      sortedScores.pop();
      place++;
    }

    return ranks;
  }
};
