# Link: https://leetcode.com/problems/coin-change-ii/description/
# Runtime: 269 ms
# Memory: 16.41 MB

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        number_of_combinations = [[0] * (amount + 1)] * (len(coins) + 1)
        for i in range(len(coins)):
            number_of_combinations[i][0] = 1
        
        for i in range(len(coins) - 1, -1, -1):
            for j in range(1, amount + 1):
                if coins[i] > j:
                    number_of_combinations[i][j] = number_of_combinations[i + 1][j]
                else:
                    number_of_combinations[i][j] = number_of_combinations[i + 1][j] + number_of_combinations[i][j - coins[i]]
        
        return number_of_combinations[i][amount]
