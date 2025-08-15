// Link: https://leetcode.com/problems/power-of-four/
// Runtime: 0 ms 
// Memory: 8 MB

class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        return (n > 0) && 
            (std::fabs(std::log10(n) / std::log10(4) - static_cast<int>(std::log10(n) / std::log10(4))) < std::numeric_limits<double>::epsilon());
    }
};