// Link: https://leetcode.com/problems/shifting-letters-ii/description/
// Runtime: 0 ms
// Memory: 97.78 MB

class Solution {
public:
  std::string shiftingLetters(const std::string &s,
                              const std::vector<std::vector<int>> &shifts) {
    std::vector<int> differences(s.size());
    for (const auto &shift : shifts) {
      if (shift[2] == 0) {
        differences[shift[0]]--;
        if (shift[1] + 1 < s.size())
          differences[shift[1] + 1]++;
      } else {
        differences[shift[0]]++;
        if (shift[1] + 1 < s.size())
          differences[shift[1] + 1]--;
      }
    }

    std::string shiftedLetters(s.size(), ' ');
    int numberOfShifts = 0;
    for (int i = 0; i < static_cast<int>(s.size()); i++) {
      numberOfShifts = (numberOfShifts + differences[i]) % 26;
      if (numberOfShifts < 0)
        numberOfShifts += 26;

      shiftedLetters[i] = 'a' + (s[i] - 'a' + numberOfShifts) % 26;
    }

    return shiftedLetters;
  }
};
