// Link: https://leetcode.com/problems/construct-k-palindrome-strings/description/
// Runtime: 4 ms
// Memory: 13.54 MB

class Solution {
public:
  bool canConstruct(const std::string &s, int k) {
    if (static_cast<int>(s.size()) < k)
      return false;
    else if (static_cast<int>(s.size()) == k)
      return true;

    std::vector<int> frequencies(26);
    for (const auto &symbol : s)
      frequencies[symbol - 'a']++;

    int numberOfOdds = 0;
    for (const auto &val : frequencies)
      if (val % 2)
        numberOfOdds++;

    return numberOfOdds <= k;
  }
};
