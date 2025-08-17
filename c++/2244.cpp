// Link: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/
// Runtime: 387 ms
// Memory: 103.5 MB

class Solution {
public:
  int minimumRounds(const std::vector<int> &tasks) {
    std::unordered_map<int, int> difficultyAndNumberOfTasks;
    for (const int &task : tasks)
      difficultyAndNumberOfTasks[task]++;

    int rounds = 0;
    for (const auto &[key, value] : difficultyAndNumberOfTasks)
      if (value == 1)
        return -1;
      else if (value % 3 == 0)
        rounds += value / 3;
      else
        rounds += value / 3 + 1;

    return rounds;
  }
};
