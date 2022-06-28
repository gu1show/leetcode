// Link: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
// Runtime: 81 ms
// Memory: 17.3 MB

class Solution
{
public:
    int minDeletions(const std::string s) 
    {
        std::vector<int> letters(26);
        for (char symbol : s)
            letters[symbol - 'a']++;
        
        std::sort(letters.begin(), letters.end());
        
        int i = 25, deletions = 0;
        std::set<int> numberLetters;
        while ((i > -1) && (letters[i] != 0))
        {
            while ((numberLetters.find(letters[i]) != numberLetters.end()) && 
                   (letters[i] != 0))
            {
                letters[i]--;
                deletions++;
            }
            numberLetters.insert(letters[i]);
            i--;
        }
        
        return deletions;
    }
};
