// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
// Runtime: 468 ms
// Memory: 9.9 MB

class Solution {
public:
  std::string removeDuplicates(const std::string &s) {
    std::string copy = s;
    for (int i = 1; i < static_cast<int>(copy.size()); i++) {
      if (copy[i - 1] == copy[i]) {
        copy.erase(copy.begin() + i - 1, copy.begin() + i + 1);
        i = std::max(0, i - 2);
      }
    }

    return copy;
  }
};
