// Link: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/
// Runtime: 76 ms
// Memory: 9 MB

class Solution {
public:
  int maxConsecutiveAnswers(const std::string &answerKey, int k) {
    int maxSize = 0;
    std::unordered_map<char, int> occurances;
    for (int right = 0; right < static_cast<int>(answerKey.size()); right++) {
      occurances[answerKey[right]]++;
      if (std::min(occurances['T'], occurances['F']) <= k)
        maxSize++;
      else
        occurances[answerKey[right - maxSize]]--;
    }

    return maxSize;
  }
};
