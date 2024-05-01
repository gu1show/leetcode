// Link: https://leetcode.com/problems/reverse-prefix-of-word/description/
// Runtime: 0 ms
// Memory: 7.48 MB

class Solution 
{
public:
    std::string reversePrefix(const std::string& word, char ch) 
    {
        std::string reversedString = word;
        short indexOfCh = 0;
        while ((indexOfCh < static_cast<short>(reversedString.size())) && (reversedString[indexOfCh] != ch))
            indexOfCh++;
        
        if (indexOfCh != static_cast<short>(reversedString.size()))
            for (int i = 0; i < indexOfCh / 2 + 1; i++)
                std::swap(reversedString[i], reversedString[indexOfCh - i]);

        return reversedString;
    }
};
