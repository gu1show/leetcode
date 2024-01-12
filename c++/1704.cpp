// Link: https://leetcode.com/problems/determine-if-string-halves-are-alike/description/
// The first solution
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

// The second solution
// Runtime: 4 ms
// Memory: 6.82 MB

class Solution 
{
public:
    bool halvesAreAlike(const std::string& s) 
    {
        int numberOfVowelsInFirstPart = 0, numberOfVowelsInSecondPart = 0;
        for (int i = 0; i < static_cast<int>(s.size() / 2); i++)
            if ((s[i] == 'a') || (s[i] == 'A') || 
                (s[i] == 'e') || (s[i] == 'E') || 
                (s[i] == 'i') || (s[i] == 'I') || 
                (s[i] == 'o') || (s[i] == 'O') || 
                (s[i] == 'u') || (s[i] == 'U'))
                numberOfVowelsInFirstPart++;

        for (int i = static_cast<int>(s.size() / 2); i < static_cast<int>(s.size()); i++)
            if ((s[i] == 'a') || (s[i] == 'A') || 
                (s[i] == 'e') || (s[i] == 'E') || 
                (s[i] == 'i') || (s[i] == 'I') || 
                (s[i] == 'o') || (s[i] == 'O') || 
                (s[i] == 'u') || (s[i] == 'U'))
                numberOfVowelsInSecondPart++;

        return numberOfVowelsInFirstPart == numberOfVowelsInSecondPart;
    }
};
