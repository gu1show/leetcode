# Link: https://leetcode.com/problems/three-consecutive-odds/description/
# Runtime: 0 ms
# Memory: 17.82 MB


class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        if len(arr) < 3:
            return False

        is_the_first_odd = arr[0] % 2 == 1
        is_the_second_odd = arr[1] % 2 == 1
        is_the_third_odd = arr[2] % 2 == 1
        for i in range(3, len(arr)):
            if is_the_first_odd and is_the_second_odd and is_the_third_odd:
                return True

            is_the_first_odd, is_the_second_odd = is_the_second_odd, is_the_third_odd
            is_the_third_odd = arr[i] % 2 == 1

        return is_the_first_odd and is_the_second_odd and is_the_third_odd
