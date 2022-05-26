// Link: https://leetcode.com/problems/number-of-1-bits/
// Runtime: 6 ms
// Memory: 5.8 MB

class Solution 
{
public:
    int hammingWeight(uint32_t n) 
    {
        int ones = 0;
        while (n > 0)
        {
            if (n % 2 == 1) ones++;
            n /= 2;
        }
        return ones;
    }
};
