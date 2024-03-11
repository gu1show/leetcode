// Link: https://leetcode.com/problems/custom-sort-string/description/
// Runtime: 0 ms
// Memory: 7.98 MB

class Solution 
{
public:
    std::string customSortString(const std::string& order, const std::string& s) 
    {
        std::unordered_map<char, int> characterAndFrequency;
        for (const auto& symbol : s)
            characterAndFrequency[symbol]++;
        
        std::string sortedString;
        for (const auto& symbol : order)
            if (characterAndFrequency[symbol] > 0)
            {
                sortedString += std::string(characterAndFrequency[symbol], symbol);
                characterAndFrequency[symbol] = 0;
            }
        
        for (const auto&[key, val] : characterAndFrequency)
            if (val > 0)
                sortedString += std::string(val, key);

        return sortedString;  
    }
};
