// Link: https://leetcode.com/problems/roman-to-integer/
// Runtime: 21 ms 
// Memory: 7.8 MB

class Solution 
{
public:
    int romanToInt(std::string s) 
    {
        std::unordered_map<char, int> values 
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int convertedValue = 0;
        for (int i = 0; i < s.size(); i++)
            if ((i < s.size() - 1) && (values[s[i]] < values[s[i + 1]])) 
                convertedValue -= values[s[i]];
            else convertedValue += values[s[i]];
        
        return convertedValue;
    }
};
