// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
// Runtime: 28 ms
// Memory: 19.7 MB

class KthLargest {
public:
  KthLargest(int k, const std::vector<int> &nums) {
    numberOfElement = k;
    for (const auto &value : nums)
      add(value);
  }

  int add(int val) {
    if (sortedValues.size() < numberOfElement)
      sortedValues.push(val);
    else if (val > sortedValues.top()) {
      sortedValues.pop();
      sortedValues.push(val);
    }

    return sortedValues.top();
  }

private:
  int numberOfElement;
  std::priority_queue<int, std::vector<int>, std::greater<int>> sortedValues;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
