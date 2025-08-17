# Link: https://leetcode.com/problems/permutations/description/
# The first solution
# Runtime: 51 ms
# Memory: 16.5 MB


class Solution:
    permutations = []

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.permutations = []
        self.__add_permutations(nums, [])

        return self.permutations

    def __add_permutations(self, nums: List[int], permutation: List[int]) -> None:
        if len(permutation) == len(nums):
            self.permutations.append(permutation[:])
        else:
            for _, value in enumerate(nums):
                if value not in permutation:
                    permutation.append(value)
                    self.__add_permutations(nums, permutation)
                    permutation.pop()


# The second solution
# Runtime: 34 ms
# Memory: 16.3 MB


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return [permutation for permutation in itertools.permutations(nums)]
