// Link: https://leetcode.com/problems/detect-capital/description/
// Runtime: 0 ms
// Memory: 6.1 MB

class Solution 
{
public:
    bool detectCapitalUse(const std::string& word) 
    {
        int upperCaseLetters = 0, i = 0;
        while (i < static_cast<int>(word.size()))
        {
            if (std::isupper(word[i])) upperCaseLetters++;

            i++;
        }

        if (((upperCaseLetters == 1) && (std::isupper(word[0]))) || 
            (upperCaseLetters == 0) || 
            (upperCaseLetters == static_cast<int>(word.size())))
            return true;
        else return false;
    }
};
