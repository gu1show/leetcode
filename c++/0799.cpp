// Link: https://leetcode.com/problems/champagne-tower/description/
// The first solution
// Runtime: 7 ms
// Memory: 43.5 MB

class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    std::vector<std::vector<double>> champagneTowerFilling(
        101, std::vector<double>(101));
    champagneTowerFilling[0][0] = poured;
    for (int row = 0; row <= query_row; row++) {
      for (int column = 0; column <= query_glass; column++) {
        double pouringOutEachSide =
            (champagneTowerFilling[row][column] - 1) / 2.0;
        if (pouringOutEachSide > 0) {
          champagneTowerFilling[row + 1][column] += pouringOutEachSide;
          champagneTowerFilling[row + 1][column + 1] += pouringOutEachSide;
        }
      }
    }

    return std::min(1.0, champagneTowerFilling[query_row][query_glass]);
  }
};

// The second solution
// Runtime: 4 ms
// Memory: 14.4 MB

class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    std::vector<double> levelOfChampagneTower{static_cast<double>(poured)};
    for (int row = 0; row < query_row; row++) {
      std::vector<double> nextLevel(levelOfChampagneTower.size() + 1);
      for (int column = 0;
           column < static_cast<int>(levelOfChampagneTower.size()); column++) {
        double pouringOutEachSide = (levelOfChampagneTower[column] - 1) / 2.0;
        if (pouringOutEachSide > 0) {
          nextLevel[column] += pouringOutEachSide;
          nextLevel[column + 1] += pouringOutEachSide;
        }
      }

      levelOfChampagneTower = nextLevel;
    }

    return std::min(1.0, levelOfChampagneTower[query_glass]);
  }
};
