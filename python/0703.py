# Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
# Runtime: 97 ms
# Memory: 20.4 MB

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.number_of_element = k
        self.sorted_values = []
        for num in nums:
            self.add(num)

    def add(self, val: int) -> int:
        if len(self.sorted_values) < self.number_of_element:
            heapq.heappush(self.sorted_values, val)
        elif val > self.sorted_values[0]:
            heapq.heapreplace(self.sorted_values, val)
        
        return self.sorted_values[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
