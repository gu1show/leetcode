// Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/
// Runtime: 76 ms
// Memory: 23.2 MB

class Solution {
public:
  int numberOfBeams(const std::vector<std::string> &bank) {
    int previousNumberOfLasers = 0, numberOfBeams = 0;
    for (const auto &row : bank) {
      int numberOfLasersInRow = 0;
      for (const auto &place : row)
        if (place == '1')
          numberOfLasersInRow++;

      if (numberOfLasersInRow > 0) {
        numberOfBeams += previousNumberOfLasers * numberOfLasersInRow;
        previousNumberOfLasers = numberOfLasersInRow;
      }
    }

    return numberOfBeams;
  }
};
