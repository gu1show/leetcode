// Link: https://leetcode.com/problems/excel-sheet-column-title/description/
// Runtime: 2 ms
// Memory: 5.91 MB

class Solution {
public:
  std::string convertToTitle(int columnNumber) {
    int number = columnNumber;
    std::string columnTitle = "";
    while (number > 0) {
      number--;
      columnTitle = static_cast<char>('A' + number % 26) + columnTitle;
      number /= 26;
    }

    return columnTitle;
  }
};
