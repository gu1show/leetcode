// Link: https://leetcode.com/problems/reverse-words-in-a-string/description/
// Runtime: 12 ms
// Memory: 7.1 MB

class Solution {
public:
  std::string reverseWords(const std::string &s) {
    std::string result;
    int i = 0;
    while (i < static_cast<int>(s.size())) {
      int j = i;
      std::string newWord;
      while ((j < static_cast<int>(s.size())) && (s[j] != ' ')) {
        newWord.push_back(s[j]);
        j++;
      }

      if ((result.size() == 0) && (newWord.size() > 0))
        result += newWord;
      else if (newWord.size() > 0) {
        newWord += " ";
        result.insert(0, newWord);
      }

      i = j + 1;
    }

    return result;
  }
};
