// Link: https://leetcode.com/problems/determine-if-string-halves-are-alike/description/
// Runtime: 8 ms
// Memory: 6.7 MB

class Solution 
{
public:
    bool halvesAreAlike(const std::string& s) 
    {
        const std::string leftPart = s.substr(0, s.size() / 2);
        const std::string rightPart = s.substr(s.size() / 2);

        return getNumberOfVowels(leftPart) == getNumberOfVowels(rightPart);
    }

private:
    const std::unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    int getNumberOfVowels(const std::string& partOfWord) 
    {
        int numberOfVowels = 0;
        for (const char& symbol : partOfWord)
            if (vowels.find(symbol) != vowels.end())
                numberOfVowels++;
        
        return numberOfVowels;
    }
};
