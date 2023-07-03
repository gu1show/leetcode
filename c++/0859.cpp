// Link: https://leetcode.com/problems/buddy-strings/description/
// Runtime: 0 ms
// Memory: 6.7 MB

class Solution 
{
public:
    bool buddyStrings(const std::string& s, const std::string& goal) 
    {
        if (s.size() != goal.size()) return false;

        int firstDifferentSymbolIndex = -1, secondDifferentSymbolIndex = -1;
        if (s == goal)
        {
            std::unordered_map<char, int> sCounter;
            for (const char& symbol : s)
            {
                sCounter[symbol]++;

                if (sCounter[symbol] > 1)
                    return true;
            }
        }
        else
        {
            for (int i = 0; i < static_cast<int>(s.size()); i++)
                if ((s[i] != goal[i]) && (firstDifferentSymbolIndex == -1))
                    firstDifferentSymbolIndex = i;
                else if ((s[i] != goal[i]) && (secondDifferentSymbolIndex == -1))
                    secondDifferentSymbolIndex = i;
                else if (s[i] != goal[i])
                    return false;
        }

        if (secondDifferentSymbolIndex == -1) return false;
        
        return s[firstDifferentSymbolIndex] == goal[secondDifferentSymbolIndex] &&
               goal[firstDifferentSymbolIndex] == s[secondDifferentSymbolIndex];
    }
};
