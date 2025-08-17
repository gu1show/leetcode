# Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/
# Runtime: 76 ms
# Memory: 19.38 MB


class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        previous_number_of_lasers, number_of_beams = 0, 0
        for row in bank:
            count_lasers = row.count("1")

            if count_lasers:
                number_of_beams += previous_number_of_lasers * count_lasers
                previous_number_of_lasers = count_lasers

        return number_of_beams
