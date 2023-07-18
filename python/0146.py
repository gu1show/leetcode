# Link: https://leetcode.com/problems/lru-cache/description/
# Runtime: 683 ms
# Memory: 77.48 MB

class LRUCache:
    capacity: int
    cache_map: OrderedDict

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache_map = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.cache_map:
            return -1

        value = self.cache_map[key]
        self.cache_map.move_to_end(key)

        return value

    def put(self, key: int, value: int) -> None:
        if key in self.cache_map:
            self.cache_map[key] = value
            self.cache_map.move_to_end(key)
            return
        
        if len(self.cache_map) >= self.capacity:
            least_recently_used_item = next(iter(self.cache_map))
            del self.cache_map[least_recently_used_item]

        self.cache_map[key] = value


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
