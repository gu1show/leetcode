# Link: https://leetcode.com/problems/combinations/description/
# Runtime: 362 ms
# Memory: 18.2 MB


class Solution:
    range_of_elements = []
    combinations = []

    def combine(self, n: int, k: int) -> List[List[int]]:
        self.range_of_elements = [element for element in range(1, n + 1)]
        self.combinations = []

        self.__add_combination([], 0, 0, k)

        return self.combinations

    def __add_combination(
        self,
        combination: List[int],
        value_for_next_element: int,
        depth: int,
        max_depth: int,
    ) -> None:
        if depth == max_depth:
            self.combinations.append(combination[:])
        else:
            for i in range(value_for_next_element, len(self.range_of_elements)):
                combination.append(self.range_of_elements[i])
                self.__add_combination(
                    combination, self.range_of_elements[i], depth + 1, max_depth
                )
                combination.pop()
