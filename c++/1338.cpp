// Link: https://leetcode.com/problems/reduce-array-size-to-the-half/
// Runtime: 213 ms
// Memory: 78.4 MB

class Solution {
public:
  int minSetSize(const std::vector<int> &arr) {
    std::unordered_map<int, int> values;
    for (const auto &val : arr)
      values[val]++;

    std::priority_queue<int> frequency;
    for (const auto &[key, value] : values)
      frequency.push(value);

    int countMinSetSize = 0, sumNumberOfValuesToRemove = 0;
    while ((frequency.size() > 0) &&
           (sumNumberOfValuesToRemove < arr.size() / 2)) {
      sumNumberOfValuesToRemove += frequency.top();
      frequency.pop();
      countMinSetSize++;
    }

    return countMinSetSize;
  }
};
