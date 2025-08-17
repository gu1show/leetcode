// Link: https://leetcode.com/problems/reverse-vowels-of-a-string/description/
// Runtime: 14 ms
// Memory: 8.2 MB

class Solution {
public:
  std::string reverseVowels(const std::string &s) {
    std::string copy = s;
    setVowels();
    int left = 0, right = static_cast<int>(s.size() - 1);
    while (left < right)
      if ((vowels.find(copy[left]) != vowels.end()) &&
          (vowels.find(copy[right]) != vowels.end())) {
        std::swap(copy[left], copy[right]);
        left++;
        right--;
      } else if (vowels.find(copy[left]) != vowels.end())
        right--;
      else
        left++;

    return copy;
  }

private:
  std::set<char> vowels;

  void setVowels() {
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
    vowels.insert('A');
    vowels.insert('E');
    vowels.insert('I');
    vowels.insert('O');
    vowels.insert('U');
  }
};
