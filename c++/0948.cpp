// Link: https://leetcode.com/problems/bag-of-tokens/description/
// Runtime: 4 ms
// Memory: 13.17 MB

class Solution {
public:
  int bagOfTokensScore(const std::vector<int> &tokens, const int power) {
    int currentPower = power;
    std::vector<int> sortedTokens = tokens;
    std::sort(sortedTokens.begin(), sortedTokens.end());

    int low = 0, high = static_cast<int>(sortedTokens.size() - 1);
    int score = 0;
    bool canStep = true;
    while ((low <= high) && (canStep)) {
      if (sortedTokens[low] <= currentPower) {
        currentPower -= sortedTokens[low];
        score++;
        low++;
      } else if ((low < high) && (score > 0)) {
        currentPower += sortedTokens[high];
        high--;
        score--;
      } else
        canStep = false;
    }

    return score;
  }
};
