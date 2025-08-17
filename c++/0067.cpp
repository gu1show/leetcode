// Link: https://leetcode.com/problems/add-binary/description/
// Runtime: 6 ms
// Memory: 6.3 MB

class Solution {
public:
  std::string addBinary(const std::string &a, const std::string &b) {
    int i = static_cast<int>(a.size() - 1), j = static_cast<int>(b.size() - 1);
    int sum = 0;
    std::string answer;
    while ((i > -1) || (j > -1) || (sum > 0)) {
      if (i > -1) {
        sum += a[i] - '0';
        i--;
      }

      if (j > -1) {
        sum += b[j] - '0';
        j--;
      }

      answer.insert(answer.begin(), sum % 2 + '0');
      sum /= 2;
    }

    return answer;
  }
};
