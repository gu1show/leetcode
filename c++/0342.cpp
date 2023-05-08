// Link: https://leetcode.com/problems/power-of-four/
// Runtime: 4 ms 
// Memory: 6 MB

class Solution 
{
public:
    bool isPowerOfFour(int n) 
    {
        if (n == 0) return false;
        else return std::floor(std::log2(n) / 2.0) == std::log2(n) / 2.0;
    }
};
