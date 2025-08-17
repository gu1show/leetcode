# Link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/
# The first solution
# Runtime: 525 ms
# Memory: 33.5 MB


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return heapq.nlargest(k, nums)[-1]


# The second solution
# Runtime: 493 ms
# Memory: 29.28 MB


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []
        for val in nums:
            heapq.heappush(heap, val)
            if len(heap) > k:
                heapq.heappop(heap)

        return heap[0]
