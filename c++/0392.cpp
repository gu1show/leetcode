// Link: https://leetcode.com/problems/is-subsequence/description/
// Runtime: 0 ms
// Memory: 6.8 MB

class Solution {
public:
  bool isSubsequence(const std::string &s, const std::string &t) {
    if (s.size() == 0)
      return true;
    else if (s.size() > t.size())
      return false;

    int i = 0, j = 0;
    while (j < static_cast<int>(t.size())) {
      if (s[i] == t[j])
        i++;
      j++;

      if (i == static_cast<int>(s.size()))
        return true;
    }

    return false;
  }
};
