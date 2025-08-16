// Link: https://leetcode.com/problems/maximum-69-number/description/
// Runtime: 0 ms
// Memory: 8.02 MB

class Solution 
{
public:
    int maximum69Number(int num) 
    {
        std::string digits = std::to_string(num);
        auto first6 = std::find(digits.begin(), digits.end(), '6');
        std::replace(first6, first6 + 1, '6', '9');

        return std::stoi(digits); 
    }
};
