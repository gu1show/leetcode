# Link: https://leetcode.com/problems/champagne-tower/description/
# The first solution
# Runtime: 78 ms
# Memory: 16.3 MB

class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        champagne_tower_filling = [[0.0] * 100 for _ in range(101)]
        champagne_tower_filling[0][0] = poured
        for row in range(query_row + 1):
            for column in range(query_glass + 1):
                pouring_out_each_side = (champagne_tower_filling[row][column] - 1) / 2
                if pouring_out_each_side > 0:
                    champagne_tower_filling[row + 1][column] += pouring_out_each_side
                    champagne_tower_filling[row + 1][column + 1] += pouring_out_each_side
        
        return min(1.0, champagne_tower_filling[query_row][query_glass])

# The second solution
# Runtime: 73 ms
# Memory: 16.16 MB

class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        level_of_champagne_tower = [poured]
        for row in range(query_row):
            next_level = [0.0] * (len(level_of_champagne_tower) + 1)
            for column in range(len(level_of_champagne_tower)):
                pouring_out_each_side = (level_of_champagne_tower[column] - 1) / 2
                if pouring_out_each_side > 0:
                    next_level[column] += pouring_out_each_side
                    next_level[column + 1] += pouring_out_each_side
            level_of_champagne_tower = next_level
        
        return min(1.0, level_of_champagne_tower[query_glass])
