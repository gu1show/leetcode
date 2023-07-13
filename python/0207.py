# Link: https://leetcode.com/problems/course-schedule/description/
# Runtime: 116 ms
# Memory: 19.1 MB

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjacent_nodes = [[] for _ in range(numCourses)]
        for requirement in prerequisites:
            adjacent_nodes[requirement[1]].append(requirement[0])
        
        is_visited, is_in_stack = [False] * numCourses, [False] * numCourses
        can_finish_all_courses = True
        i = 0
        while (i < numCourses) and (can_finish_all_courses):
            if (self.__dfs(i, adjacent_nodes, is_visited, is_in_stack)):
                can_finish_all_courses = False
            i += 1
        
        return can_finish_all_courses
    

    def __dfs(self, node_index: int, adjacent_nodes: List[List[int]], is_visited: List[bool], is_in_stack: List[bool]) -> bool:
        if is_in_stack[node_index]:
            return True
        elif is_visited[node_index]:
            return False
        
        is_in_stack[node_index] = True
        is_visited[node_index] = True

        for neighbour in adjacent_nodes[node_index]:
            if self.__dfs(neighbour, adjacent_nodes, is_visited, is_in_stack):
                return True

        is_in_stack[node_index] = False

        return False
