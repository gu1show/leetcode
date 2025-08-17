// Link: https://leetcode.com/problems/find-eventual-safe-states/description/
// Runtime: 270 ms
// Memory: 68 MB

class Solution {
public:
  std::vector<int>
  eventualSafeNodes(const std::vector<std::vector<int>> &graph) {
    std::vector<int> outdegree(graph.size());
    std::vector<bool> isSafeNode(graph.size());
    std::queue<int> nodesForDeleting;
    std::unordered_map<int, std::vector<int>> connectionWithNodes;
    for (int i = 0; i < static_cast<int>(graph.size()); i++) {
      outdegree[i] = static_cast<int>(graph[i].size());
      if (outdegree[i] == 0) {
        isSafeNode[i] = true;
        nodesForDeleting.push(i);
      }
      for (int j = 0; j < static_cast<int>(graph[i].size()); j++)
        connectionWithNodes[graph[i][j]].push_back(i);
    }

    while (!nodesForDeleting.empty()) {
      int nodeIndex = nodesForDeleting.front();
      nodesForDeleting.pop();

      for (const auto &value : connectionWithNodes[nodeIndex]) {
        outdegree[value]--;
        if (outdegree[value] == 0) {
          nodesForDeleting.push(value);
          isSafeNode[value] = true;
        }
      }
    }

    std::vector<int> safeNodes;
    for (int i = 0; i < static_cast<int>(isSafeNode.size()); i++)
      if (isSafeNode[i])
        safeNodes.push_back(i);

    return safeNodes;
  }
};
