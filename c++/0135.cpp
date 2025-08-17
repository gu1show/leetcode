// Link: https://leetcode.com/problems/candy/
// Runtime: 43 ms
// Memory: 18.3 MB

class Solution {
public:
  int candy(const std::vector<int> &ratings) {
    int size = ratings.size();
    std::vector<int> leftToRight(size, 1), rightToLeft(size, 1);

    for (int i = 0; i < size - 1; i++)
      if (ratings[i] < ratings[i + 1])
        leftToRight[i + 1] = leftToRight[i] + 1;

    for (int i = size - 2; i > -1; i--)
      if (ratings[i] > ratings[i + 1])
        rightToLeft[i] = rightToLeft[i + 1] + 1;

    int sum = 0;
    for (int i = 0; i < size; i++)
      sum += std::max(leftToRight[i], rightToLeft[i]);

    return sum;
  }
};
