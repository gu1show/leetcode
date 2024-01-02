# Link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/
# Runtime: 57 ms
# Memory: 17.4 MB

class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        table_with_used_elements = defaultdict(set)
        array_with_conditions = []

        for val in nums:
            i, is_found = 0, False
            while (i < len(table_with_used_elements)) and (not is_found):
                if val not in table_with_used_elements[i]:
                    is_found = True
                i += 1
            
            if is_found:
                table_with_used_elements[i - 1].add(val)
                array_with_conditions[i - 1].append(val)
            else:
                table_with_used_elements[i].add(val)
                array_with_conditions.append([val])
        
        return array_with_conditions
