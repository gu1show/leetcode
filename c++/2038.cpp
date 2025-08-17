// Link: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/
// Runtime: 39 ms
// Memory: 12.1 MB

class Solution {
public:
  bool winnerOfGame(const std::string &colors) {
    int aliceScore = 0, bobScore = 0;
    for (int i = 1; i < static_cast<int>(colors.size() - 1); i++) {
      if ((colors[i - 1] == colors[i]) && (colors[i] == colors[i + 1]) &&
          (colors[i] == 'A'))
        aliceScore++;
      else if ((colors[i - 1] == colors[i]) && (colors[i] == colors[i + 1]))
        bobScore++;
    }

    return aliceScore > bobScore;
  }
};
