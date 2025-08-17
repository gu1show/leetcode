// Link: https://leetcode.com/problems/crawler-log-folder/description/
// Runtime: 0 ms
// Memory: 13.81 MB

class Solution {
public:
  int minOperations(const std::vector<std::string> &logs) {
    int minimumOperatonsToGoBack = 0;
    for (const auto &log : logs)
      if (log == "../")
        minimumOperatonsToGoBack = std::max(0, minimumOperatonsToGoBack - 1);
      else if (log != "./")
        minimumOperatonsToGoBack += 1;

    return minimumOperatonsToGoBack;
  }
};
