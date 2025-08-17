// Link: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// Runtime: 46 ms
// Memory: 11.6 MB

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  std::vector<std::vector<int>> levelOrder(Node *root) {
    if (root != nullptr) {
      std::vector<std::vector<int>> result;
      std::queue<Node *> nodes;
      nodes.push(root);
      while (!nodes.empty()) {
        result.push_back({});
        auto size = nodes.size();
        while (size > 0) {
          Node *tempNode = nodes.front();
          nodes.pop();
          result.back().push_back(tempNode->val);
          for (Node *child : tempNode->children)
            nodes.push(child);
          size--;
        }
      }

      return result;
    } else
      return {};
  }
};
