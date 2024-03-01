// Link: https://leetcode.com/problems/maximum-odd-binary-number/description/
// Runtime: 2 ms
// Memory: 8.63 MB

class Solution 
{
public:
    std::string maximumOddBinaryNumber(const std::string& s) 
    {
        int numberOfOnes = 0;
        for (const auto& symbol : s)
            if (symbol == '1')
                numberOfOnes++;
        
        return std::string(numberOfOnes - 1, '1') + std::string(s.size() - numberOfOnes, '0') + '1';
    }
};
