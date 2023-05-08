// Link: https://leetcode.com/problems/power-of-three/
// Runtime: 27 ms 
// Memory: 6.2 MB

class Solution 
{
public:
    bool isPowerOfThree(int n) 
    {
        if (n <= 0) return false;
        else return std::floor(std::log10(n) / std::log10(3)) == std::log10(n) / std::log10(3);
    }
};
