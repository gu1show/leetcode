# Link: https://leetcode.com/problems/number-of-senior-citizens/description/
# Runtime: 39 ms
# Memory: 16.57 MB

class Solution:
    def countSeniors(self, details: List[str]) -> int:
        number_of_seniors = 0
        for information in details:
            if int(information[11]) > 6:
                number_of_seniors += 1
            elif (int(information[11]) == 6) and (int(information[12]) > 0):
                number_of_seniors += 1
        
        return number_of_seniors
