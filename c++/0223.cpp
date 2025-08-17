// Link: https://leetcode.com/problems/rectangle-area/description/
// Runtime: 24 ms
// Memory: 6 MB

class Solution {
public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    int xOverlap = std::max(0, std::min(ax2, bx2) - std::max(ax1, bx1));
    int yOverlap = std::max(0, std::min(ay2, by2) - std::max(ay1, by1));

    return computeSquareArea(ax1, ay1, ax2, ay2) +
           computeSquareArea(bx1, by1, bx2, by2) - xOverlap * yOverlap;
  }

private:
  int computeSquareArea(int ax1, int ay1, int ax2, int ay2) {
    return (ax2 - ax1) * (ay2 - ay1);
  }
};
