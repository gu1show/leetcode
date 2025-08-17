// Link: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
// The first solution
// Runtime: 81 ms
// Memory: 17.3 MB

class Solution {
public:
  int minDeletions(const std::string &s) {
    std::vector<int> letters(26);
    for (char symbol : s)
      letters[symbol - 'a']++;

    std::sort(letters.begin(), letters.end());

    int i = 25, deletions = 0;
    std::set<int> numberLetters;
    while ((i > -1) && (letters[i] != 0)) {
      while ((numberLetters.find(letters[i]) != numberLetters.end()) &&
             (letters[i] != 0)) {
        letters[i]--;
        deletions++;
      }
      numberLetters.insert(letters[i]);
      i--;
    }

    return deletions;
  }
};

// The second solution
// Runtime: 54 ms
// Memory: 14.69 MB

class Solution {
public:
  int minDeletions(const std::string &s) {
    std::vector<int> charFrequency(26);
    for (const auto &symbol : s)
      charFrequency[symbol - 'a']++;

    std::sort(charFrequency.begin(), charFrequency.end());
    int numberOfDeletions = 0;
    for (int i = 24; i > -1; i--) {
      if ((charFrequency[i] >= charFrequency[i + 1]) &&
          (charFrequency[i] != 0)) {
        int frequency = charFrequency[i];
        charFrequency[i] = std::max(0, charFrequency[i + 1] - 1);
        numberOfDeletions += frequency - charFrequency[i];
      }
    }

    return numberOfDeletions;
  }
};
