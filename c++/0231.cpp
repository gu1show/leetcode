// Link: https://leetcode.com/problems/power-of-two/description/
// Runtime: 0 ms
// Memory: 7.13 MB

class Solution 
{
public:
    bool isPowerOfTwo(int n) 
    {
        if (n < 1)
            return false;

        return std::fabs(std::log2(n) - static_cast<int>(std::log2(n))) < std::numeric_limits<double>::epsilon();
    }
};
