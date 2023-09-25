// Link: https://leetcode.com/problems/find-the-difference/description/
// Runtime: 0 ms
// Memory: 7.1 MB

class Solution 
{
public:
    char findTheDifference(const std::string& s, const std::string& t) 
    {
        std::unordered_map<char, int> symbolsAndFrequencyS;
        for (const auto& symbol : s)
            symbolsAndFrequencyS[symbol]++;

        for (const auto& symbol : t)
        {
            symbolsAndFrequencyS[symbol]--;
            if (symbolsAndFrequencyS[symbol] < 0) return symbol;
        }

        return ' ';
    }
};
