// Link: https://leetcode.com/problems/flatten-nested-list-iterator/
// Runtime: 22 ms
// Memory: 14.3 MB

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
  NestedIterator(const std::vector<NestedInteger> &nestedList) {
    flattenList(nestedList);
  }

  void flattenList(const std::vector<NestedInteger> &nestedList) {
    for (auto value : nestedList) {
      if (value.isInteger())
        elements.push_back(value.getInteger());
      else
        flattenList(value.getList());
    }
  }

  int next() { return elements[position++]; }

  bool hasNext() { return elements.size() > position; }

private:
  std::vector<int> elements;
  int position = 0;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
