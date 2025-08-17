// Link: https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/
// Runtime: 864 ms
// Memory: 162.7 MB

class Solution {
public:
  std::vector<std::vector<int>>
  findWinners(const std::vector<std::vector<int>> &matches) {
    for (const auto &match : matches) {
      updateTable(match[0], true);
      updateTable(match[1], false);
    }

    std::vector<std::vector<int>> zeroAndOneLosses(2);
    for (const auto &[key, val] : scoreTable) {
      if (val.second == 0)
        zeroAndOneLosses[0].push_back(key);
      else if (val.second == 1)
        zeroAndOneLosses[1].push_back(key);
    }

    return zeroAndOneLosses;
  }

private:
  std::map<int, std::pair<int, int>> scoreTable;

  void updateTable(int participant, bool isWin) {
    if (scoreTable.find(participant) != scoreTable.end()) {
      std::pair<int, int> score = scoreTable[participant];
      if (isWin)
        score.first++;
      else
        score.second++;
      scoreTable[participant] = score;
    } else {
      std::pair<int, int> score;
      if (isWin)
        score = std::make_pair(1, 0);
      else
        score = std::make_pair(0, 1);
      scoreTable[participant] = score;
    }
  }
};
