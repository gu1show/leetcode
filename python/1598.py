# Link: https://leetcode.com/problems/crawler-log-folder/description/
# Runtime: 55 ms
# Memory: 16.78 MB

class Solution:
    def minOperations(self, logs: List[str]) -> int:
        minimum_operatons_to_go_back = 0
        for log in logs:
            if log == '../':
                minimum_operatons_to_go_back = max(0, minimum_operatons_to_go_back - 1)
            elif log != './':
                minimum_operatons_to_go_back += 1
        
        return minimum_operatons_to_go_back
