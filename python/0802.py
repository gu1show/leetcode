# Link: https://leetcode.com/problems/find-eventual-safe-states/description/
# Runtime: 832 ms
# Memory: 25.1 MB

import queue


class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        outdegree = [0] * len(graph)
        is_safe_node = [False] * len(graph)
        nodes_for_deleting = queue.Queue()
        connection_with_nodes = defaultdict(lambda: [])
        for i, connected_nodes in enumerate(graph):
            outdegree[i] = len(connected_nodes)
            if outdegree[i] == 0:
                is_safe_node[i] = True
                nodes_for_deleting.put(i)
            
            for node_index in connected_nodes:
                connection_with_nodes[node_index].append(i)
        
        while not nodes_for_deleting.empty():
            node_index = nodes_for_deleting.get()

            for node in connection_with_nodes[node_index]:
                outdegree[node] -= 1
                if outdegree[node] == 0:
                    nodes_for_deleting.put(node)
                    is_safe_node[node] = True
        
        safe_nodes = []
        for i, can_add in enumerate(is_safe_node):
            if can_add:
                safe_nodes.append(i)
        
        return safe_nodes
