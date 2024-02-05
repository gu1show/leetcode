// Link: https://leetcode.com/problems/first-unique-character-in-a-string/description/
// Runtime: 17 ms
// Memory: 10.8 MB

class Solution 
{
public:
    int firstUniqChar(const std::string& s) 
    {
        std::vector<int> symbolAndFrequency(26);
        for (const auto& symbol : s)
            symbolAndFrequency[symbol - 'a']++;
        
        for (int i = 0; i < static_cast<int>(s.size()); i++)
            if (symbolAndFrequency[s[i] - 'a'] == 1)
                return i;

        return -1;
    }
};
