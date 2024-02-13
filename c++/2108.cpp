// Link: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/
// Runtime: 42 ms
// Memory: 23.24 MB

class Solution 
{
public:
    std::string firstPalindrome(const std::vector<std::string>& words) 
    {
        for (const auto& word : words)
        {
            int i = 0;
            bool isPalindrome = true;
            while ((i < static_cast<int>(word.size() / 2)) && (isPalindrome))
            {
                if (word[i] != word[word.size() - 1 - i])
                    isPalindrome = false;

                i++;
            }

            if (isPalindrome)
                return word;
        }

        return "";
    }
};
