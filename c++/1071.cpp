// Link: https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
// Runtime: 6 ms 
// Memory: 7.1 MB

class Solution 
{
public:
    std::string gcdOfStrings(const std::string& str1, const std::string& str2) 
    {
        if (str1 + str2 == str2 + str1) return str1.substr(0, std::gcd(str1.size(), str2.size()));
        else return "";
    }
};
