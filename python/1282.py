# Link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/
# Runtime: 71 ms
# Memory: 16.61 MB

class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        group_size_and_people = defaultdict(lambda: [])
        for index, value in enumerate(groupSizes):
            group_size_and_people[value].append(index)
        
        groups = []
        for group_size, people in group_size_and_people.items():
            while people:
                groups.append(people[:group_size])
                del people[:group_size]
        
        return groups
