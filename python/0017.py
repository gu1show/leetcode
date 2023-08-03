# Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
# Runtime: 40 ms
# Memory: 16.42 MB

class Solution:
    buttons: Dict[str, str] = {}
    combinations: List[str] = []

    def __init__(self):
        self.buttons['2'] = 'abc'
        self.buttons['3'] = 'def'
        self.buttons['4'] = 'ghi'
        self.buttons['5'] = 'jkl'
        self.buttons['6'] = 'mno'
        self.buttons['7'] = 'pqrs'
        self.buttons['8'] = 'tuv'
        self.buttons['9'] = 'wxyz'

    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0: return []

        self.combinations = []
        self.__add_combinations(digits, "", 0)

        return self.combinations

        
    def __add_combinations(self, digits: str, combination: str, depth: int) -> None:
        if len(digits) == depth: self.combinations.append(combination)
        else:
            for symbol in self.buttons[digits[depth]]:
                combination += symbol
                self.__add_combinations(digits, combination, depth + 1)
                combination = combination[:-1]
