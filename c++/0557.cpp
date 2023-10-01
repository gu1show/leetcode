// Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Runtime: 14 ms
// Memory: 10.1 MB

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

            i = j + 1;
        }
        
        return reversedWords;
    }
};
