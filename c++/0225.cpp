// Link: https://leetcode.com/problems/implement-stack-using-queues/
// Runtime: 0 ms
// Memory: 6.8 MB

class MyStack {
public:
  MyStack() {}

  void push(int x) {
    peek = x;
    container.push(x);
  }

  int pop() {
    int size = container.size() - 1;
    while (size > 0) {
      peek = container.front();
      container.push(peek);
      container.pop();

      size--;
    }
    int topElement = container.front();
    container.pop();

    return topElement;
  }

  int top() { return peek; }

  bool empty() { return container.empty(); }

private:
  std::queue<int> container;
  int peek = 0;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */