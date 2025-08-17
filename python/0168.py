# Link: https://leetcode.com/problems/excel-sheet-column-title/description/
# Runtime: 34 ms
# Memory: 16.34 MB


class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        number = columnNumber
        column_title = ""
        while number != 0:
            number -= 1
            column_title = chr(ord("A") + number % 26) + column_title
            number //= 26

        return column_title
