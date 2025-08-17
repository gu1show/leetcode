// Link: https://leetcode.com/problems/fibonacci-number/
// The first solution
// Runtime: 19 ms
// Memory: 5.8 MB

class Solution {
public:
  int fib(int n) {
    if (n == 0)
      return 0;
    else if (n == 1)
      return 1;
    else
      return fib(n - 1) + fib(n - 2);
  }
};

// The second solution
// Runtime: 3 ms
// Memory: 6.1 MB

class Solution {
public:
  int fib(int n) {
    if (n == 0)
      return 0;
    else if (n == 1)
      return 1;
    else {
      std::vector<int> fibonacci(n + 1);
      fibonacci[0] = 0;
      fibonacci[1] = 1;
      for (int i = 2; i < n + 1; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];

      return fibonacci[n];
    }
  }
};

// The third solution
// Runtime: 0 ms
// Memory: 5.9 MB

class Solution {
public:
  int fib(int n) {
    if (n == 0)
      return 0;
    else if (n == 1)
      return 1;
    else {
      int previous1 = 1, previous2 = 0, current = 1;
      for (int i = 2; i < n + 1; i++) {
        current = previous1 + previous2;
        previous2 = previous1;
        previous1 = current;
      }

      return current;
    }
  }
};
