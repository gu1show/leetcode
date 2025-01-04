// Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/
// Runtime: 131 ms
// Memory: 14.65 MB

class Solution 
{
public:
    int countPalindromicSubsequence(const std::string& s) 
    {
        std::vector<int> firstOccurrenceIndex(26, -1);
        std::vector<int> lastOccurrenceIndex(26, -1);
        for (int i = 0; i < static_cast<int>(s.size()); i++) 
        {
            if (firstOccurrenceIndex[s[i] - 'a'] == -1)
                firstOccurrenceIndex[s[i] - 'a'] = i;
            
            lastOccurrenceIndex[s[i] - 'a'] = i;
        }

        int numberOfPalindromesLength3 = 0;
        for (int i = 0; i < 26; i++)
            if (firstOccurrenceIndex[i] != lastOccurrenceIndex[i])
            {
                std::unordered_set<char> charsBetween;
                for (int j = firstOccurrenceIndex[i] + 1; j < lastOccurrenceIndex[i]; j++)
                    charsBetween.insert(s[j]);
                
                numberOfPalindromesLength3 += static_cast<int>(charsBetween.size());
            }

        return numberOfPalindromesLength3;
    }
};
