# Link: https://leetcode.com/problems/implement-stack-using-queues/description/
# Runtime: 38 ms
# Memory: 16.38 MB

import queue


class MyStack:
    def __init__(self):
        self.stack_imitation = queue.Queue()
        self.peek = 0

    def push(self, x: int) -> None:
        self.stack_imitation.put(x)
        self.peek = x

    def pop(self) -> int:
        size = self.stack_imitation.qsize()
        while size > 1:
            self.peek = self.stack_imitation.get()
            self.stack_imitation.put(self.peek)
            size -= 1

        top_value = self.stack_imitation.get()

        return top_value

    def top(self) -> int:
        return self.peek

    def empty(self) -> bool:
        return self.stack_imitation.empty()


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
