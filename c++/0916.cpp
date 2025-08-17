// Link: https://leetcode.com/problems/word-subsets/
// Runtime: 920 ms
// Memory: 144 MB

class Solution {
public:
  std::vector<std::string> wordSubsets(const std::vector<std::string> &words1,
                                       const std::vector<std::string> &words2) {
    std::vector<std::string> universalStrings;

    std::vector<int> maxFrequency(26);
    for (const auto &subset : words2) {
      std::vector<int> frequency = getFrequency(subset);
      for (int i = 0; i < 26; i++)
        maxFrequency[i] = std::max(maxFrequency[i], frequency[i]);
    }

    std::string minSubset;
    for (int i = 0; i < 26; i++)
      if (maxFrequency[i] > 0)
        while (maxFrequency[i] > 0) {
          minSubset.push_back(static_cast<char>(i + 'a'));
          maxFrequency[i]--;
        }

    for (const auto &str : words1)
      if (canAddWord(str, minSubset))
        universalStrings.push_back(str);

    return universalStrings;
  }

private:
  bool canAddWord(const std::string &word, const std::string &minSubset) {
    std::unordered_map<char, int> letters;
    for (const auto &c : word)
      letters[c]++;

    bool canAddWord = true;
    int i = 0;
    while (i < minSubset.size()) {
      if (letters.find(minSubset[i]) != letters.end())
        letters[minSubset[i]]--;
      else
        canAddWord = false;
      i++;
    }

    for (const auto &[key, value] : letters)
      if (value < 0)
        canAddWord = false;

    return canAddWord;
  }

  std::vector<int> getFrequency(const std::string &subset) {
    std::vector<int> frequency(26);
    for (const char &c : subset)
      frequency[c - 'a']++;

    return frequency;
  }
};
