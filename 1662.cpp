// Link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
// Runtime: 13 ms
// Memory: 11.5 MB

class Solution 
{
public:
    bool arrayStringsAreEqual(const std::vector<std::string>& word1, const std::vector<std::string>& word2)
    {
        std::string firstWord;
        for (const auto& str : word1)
            firstWord += str;
        
        std::string secondWord;
        for (const auto& str : word2)
            secondWord += str;
        
        return firstWord == secondWord;
    }
};
