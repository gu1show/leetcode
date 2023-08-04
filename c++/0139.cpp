// Link: https://leetcode.com/problems/word-break/description/
// Runtime: 15 ms
// Memory: 13 MB

class Solution 
{
public:
    bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict) 
    {
        std::vector<bool> ending(s.size() + 1);
        ending[0] = true;

        for (int i = 1; i < static_cast<int>(s.size() + 1); i++)
        {
            int j = 0;
            bool isFound = false;
            while ((j < i) && (!isFound))
            {
                if ((ending[j]) && (std::find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()))
                {
                    ending[i] = true;
                    isFound = true;
                }

                j++;
            }
        }

        return ending[s.size()];
    }
};
