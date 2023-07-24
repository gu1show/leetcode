# Link: https://leetcode.com/problems/powx-n/description/
# Runtime: 43 ms
# Memory: 16.4 MB

class Solution:
    def myPow(self, x: float, n: int) -> float:
        product = self.__multiplier(x, abs(n))
        return product if n >= 0 else 1 / product
        
    def __multiplier(self, x: float, n: int) -> float:
        if n == 0: return 1
        elif x == 0: return 0

        product = self.__multiplier(x * x, n // 2)
        return x * product if n % 2 == 1 else product
