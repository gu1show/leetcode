# Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
# Runtime: 1157 ms
# Memory: 55 MB


class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        waysToNodes = [0] * n
        for edge in edges:
            waysToNodes[edge[1]] += 1

        unreachableNodes = []
        for index, value in enumerate(waysToNodes):
            if value == 0:
                unreachableNodes.append(index)

        return unreachableNodes
