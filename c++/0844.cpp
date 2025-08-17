// Link: https://leetcode.com/problems/backspace-string-compare/
// The first solution
// Runtime: 7 ms
// Memory: 6.2 MB

class Solution {
public:
  bool backspaceCompare(std::string &s, std::string &t) {
    changeString(s);
    changeString(t);

    return s == t;
  }

  void changeString(std::string &str) {
    while (str.find('#') != std::string::npos) {
      std::size_t index = str.find('#');
      str.erase(str.begin() + index);
      if (index != 0)
        str.erase(str.begin() + index - 1);
    }
  }
};

// The second solution
// Runtime: 0 ms
// Memory: 6.2 MB

class Solution {
public:
  bool backspaceCompare(std::string &s, std::string &t) {
    return changeString(s) == changeString(t);
  }

  std::string changeString(const std::string &str) {
    std::string result;
    for (char symbol : str)
      if (symbol != '#')
        result.push_back(symbol);
      else if (!result.empty())
        result.pop_back();
    return result;
  }
};
