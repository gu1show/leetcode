// Link: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
// Runtime: 833 ms
// Memory: 167.8 MB

class Solution
{
public:
    int longestPalindrome(const std::vector<std::string>& words)
    {
        int palindromeLength = 0;
        std::unordered_map<std::string, int> wordCounter;
        for (const auto& word : words) 
        {
            std::string reversedWord = word;
            std::swap(reversedWord[0], reversedWord[1]);
            if (wordCounter[reversedWord] > 0)
            {
                palindromeLength += 4;
                wordCounter[reversedWord]--;
            }
            else wordCounter[word]++;
        }
        
        std::unordered_map<std::string, int>::iterator it = wordCounter.begin();
        bool hasStringWithDoubledLetters = false;
        while ((it != wordCounter.end()) && (!hasStringWithDoubledLetters))
        {
            std::string key = it->first;
            int value = it->second;
            if ((key[0] == key[1]) && (value > 0))
            {
                palindromeLength += 2 * value;
                wordCounter[key]--;
                hasStringWithDoubledLetters = true;
            }
            
            ++it;
        }
        
        return palindromeLength;
    }
};
