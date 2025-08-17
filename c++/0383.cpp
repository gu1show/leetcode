// Link: https://leetcode.com/problems/ransom-note/
// Runtime: 45 ms
// Memory: 8.1 MB

class Solution {
public:
  bool canConstruct(const std::string &ransomNote,
                    const std::string &magazine) {
    std::unordered_map<char, int> countingChars;
    for (const auto &c : magazine)
      countingChars[c]++;

    for (const auto &c : ransomNote)
      countingChars[c]--;

    bool containAll = true;
    auto it = countingChars.begin();
    while ((it != countingChars.end()) && (containAll)) {
      if (it->second < 0)
        containAll = false;
      ++it;
    }

    return containAll;
  }
};
