// Link: https://leetcode.com/problems/number-of-senior-citizens/description/
// Runtime: 4 ms
// Memory: 17.69 MB

class Solution {
public:
  int countSeniors(const std::vector<std::string> &details) {
    int numberOfSeniors = 0;
    for (const auto &information : details)
      if (information[11] - '0' > 6)
        numberOfSeniors++;
      else if ((information[11] - '0' == 6) && (information[12] - '0' > 0))
        numberOfSeniors++;

    return numberOfSeniors;
  }
};
