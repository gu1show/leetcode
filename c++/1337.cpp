// Link: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
// Runtime: 9 ms
// Memory: 11 MB

class Solution {
public:
  std::vector<int> kWeakestRows(const std::vector<vector<int>> &mat, int k) {
    std::map<int, std::vector<int>> frequencyAndNumbersOfRows;
    for (int i = 0; i < static_cast<int>(mat.size()); i++)
      frequencyAndNumbersOfRows[std::reduce(mat[i].begin(), mat[i].end())]
          .push_back(i);

    int numbersFound = 0;
    std::vector<int> weakestRows;
    for (const auto &[key, value] : frequencyAndNumbersOfRows) {
      int i = 0;
      while ((numbersFound < k) && (i < static_cast<int>(value.size()))) {
        weakestRows.push_back(value[i]);
        numbersFound++;
        i++;
      }
    }

    return weakestRows;
  }
};
