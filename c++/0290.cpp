// Link: https://leetcode.com/problems/word-pattern/description/
// Runtime: 0 ms
// Memory: 6.5 MB

class Solution 
{
public:
    bool wordPattern(const std::string& pattern, const std::string& s) 
    {
        std::vector<std::string> words;
        getAllWords(s, words);

        if (static_cast<int>(pattern.size()) != static_cast<int>(words.size())) return false;

        int i = 0;
        bool isCorrect = true;
        while ((i < static_cast<int>(pattern.size())) && (isCorrect))
        {
            if ((relationLetterToWord.find(pattern[i]) == relationLetterToWord.end()) &&
                (relationWordToLetter.find(words[i]) == relationWordToLetter.end()))
            {
                relationLetterToWord[pattern[i]] = words[i];
                relationWordToLetter[words[i]] = pattern[i];
            }
            else if ((relationLetterToWord[pattern[i]] != words[i]) ||
                     (relationWordToLetter[words[i]] != pattern[i])) 
                    isCorrect = false;

            i++;
        }
        
        return isCorrect;
    }

private:
    std::unordered_map<char, std::string> relationLetterToWord;
    std::unordered_map<std::string, char> relationWordToLetter;

    void getAllWords(const std::string& source, std::vector<std::string>& destination) 
    {
        int i = 0;
        while (i < static_cast<int>(source.size())) 
        {
            std::string word;
            while ((i < static_cast<int>(source.size())) && (source[i] != ' ')) 
            {
                word.push_back(source[i]);
                i++;
            }
            destination.push_back(word);
            i++;
        }
    }
};
