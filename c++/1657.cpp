// Link: https://leetcode.com/problems/determine-if-two-strings-are-close/description/
// Runtime: 253 ms
// Memory: 18.9 MB

class Solution {
public:
  bool closeStrings(const std::string &word1, const std::string &word2) {
    std::vector<int> frequencyWord1(26), frequencyWord2(26), lettersWord1(26),
        lettersWord2(26);

    for (const char &symbol : word1) {
      frequencyWord1[symbol - 'a']++;
      lettersWord1[symbol - 'a'] = 1;
    }

    for (const char &symbol : word2) {
      frequencyWord2[symbol - 'a']++;
      lettersWord2[symbol - 'a'] = 1;
    }

    std::sort(frequencyWord1.begin(), frequencyWord1.end());
    std::sort(frequencyWord2.begin(), frequencyWord2.end());

    return frequencyWord1 == frequencyWord2 && lettersWord1 == lettersWord2;
  }
};
