// Link: https://leetcode.com/problems/valid-sudoku/description/
// Runtime: 27 ms
// Memory: 20.7 MB

class Solution {
public:
  bool isValidSudoku(const std::vector<std::vector<char>> &board) {
    short i = 0;
    bool isValid = true;
    while ((i < 9) && (isValid)) {
      short j = 0;
      while ((j < 9) && (isValid)) {
        if (board[i][j] != '.') {
          short value = board[i][j] - '0';
          if ((horizontals[i].count(value) == 0) &&
              (verticals[j].count(value) == 0) &&
              (squares[(i / 3) * 3 + j / 3].count(value) == 0)) {
            horizontals[i].insert(value);
            verticals[j].insert(value);
            squares[(i / 3) * 3 + j / 3].insert(value);
          } else
            isValid = false;
        }

        j++;
      }

      i++;
    }

    return isValid;
  }

private:
  std::unordered_map<short, std::set<short>> horizontals;
  std::unordered_map<short, std::set<short>> verticals;
  std::unordered_map<short, std::set<short>> squares;
};
