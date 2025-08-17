// Link: https://leetcode.com/problems/reordered-power-of-2/
// Runtime: 0 ms
// Memory: 6.2 MB

class Solution {
public:
  bool reorderedPowerOf2(int n) {
    std::vector<int> digitsOfN = countDigits(n);

    bool isReorderedPowerOf2 = false;
    int i = 0;
    while ((i < 30) && (!isReorderedPowerOf2)) {
      std::vector<int> digitOfPowerOf2 = countDigits(1 << i);

      int j = 0;
      bool isEqual = true;
      while ((j < 10) && (isEqual)) {
        if (digitsOfN[j] != digitOfPowerOf2[j])
          isEqual = false;
        j++;
      }

      if (isEqual)
        isReorderedPowerOf2 = true;
      i++;
    }

    return isReorderedPowerOf2;
  }

private:
  std::vector<int> countDigits(int n) {
    std::vector<int> digits(10);
    while (n > 0) {
      digits[n % 10]++;
      n /= 10;
    }

    return digits;
  }
};
