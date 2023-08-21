// Link: https://leetcode.com/problems/repeated-substring-pattern/description/
// Runtime: 16 ms
// Memory: 12.69 MB

class Solution 
{
public:
    bool repeatedSubstringPattern(const std::string& s) 
    {
        std::string doubleString = s + s;
        if (doubleString.substr(1, static_cast<int>(doubleString.size()) - 2).find(s) != -1) return true;
        else return false;
    }
};
