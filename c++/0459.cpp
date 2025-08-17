// Link: https://leetcode.com/problems/repeated-substring-pattern/description/
// Runtime: 6 ms
// Memory: 14.21 MB

class Solution {
public:
  bool repeatedSubstringPattern(const std::string &s) {
    std::string doubleString = s + s;

    return doubleString.substr(1, static_cast<int>(doubleString.size()) - 2)
               .find(s) != -1;
  }
};
