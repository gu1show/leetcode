// Link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
// Runtime: 328 ms
// Memory: 94.5 MB

class Solution {
public:
  int minCost(const std::string &colors, const std::vector<int> &neededTime) {
    int time = 0;
    for (int i = 0; i < colors.size() - 1; i++)
      if (colors[i] == colors[i + 1]) {
        int j = i + 1;
        while ((j < colors.size()) && (colors[j - 1] == colors[j]))
          j++;

        int maxValue = neededTime[i], maxIndex = i;
        for (int k = i; k < j; k++)
          if (maxValue < neededTime[k]) {
            maxValue = neededTime[k];
            maxIndex = k;
          }

        for (int k = i; k < j; k++)
          if (k != maxIndex)
            time += neededTime[k];

        i = j - 1;
      }

    return time;
  }
};
