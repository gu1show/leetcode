# Link: https://leetcode.com/problems/top-k-frequent-elements/description/
# Runtime: 100 ms
# Memory: 21.1 MB

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        most_common = counter.most_common(k)

        return [pair[0] for pair in most_common]
