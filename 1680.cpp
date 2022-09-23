// Link: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
// Runtime: 156 ms
// Memory: 5.9 MB

class Solution
{
public:
    int concatenatedBinary(int n)
    {
        long value = 0;
        for (int i = 1; i <= n; i++)
        {
            int lengthBinary = std::log2(i) + 1;
            value = ((value << lengthBinary) % 1000000007 + i) % 1000000007;
        }
        
        return value;
    }
};
