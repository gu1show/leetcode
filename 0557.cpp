// Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Runtime: 7 ms
// Memory: 9.7 MB

class Solution {
public:
    std::string reverseWords(const std::string& s) 
    {
        std::string reversedWords = s;
        
        int i = 0;
        while (i < reversedWords.size())
        {
            int j = i;
            while ((j < reversedWords.size()) && (reversedWords[j] != ' ')) j++;
            for (int k = i; k < i + (j - i) / 2; k++)
                std::swap(reversedWords[k], reversedWords[j - k + i - 1]);
            j++;
            i = j;
        }
        
        return reversedWords;
    }
};
