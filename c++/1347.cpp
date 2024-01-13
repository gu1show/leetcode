// Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/
// Runtime: 50 ms
// Memory: 14.47 MB

class Solution 
{
public:
    int minSteps(const std::string& s, const std::string& t) 
    {
        std::vector<int> allFrequencies(26);
        for (int i = 0; i < static_cast<int>(s.size()); i++)
        {
            allFrequencies[s[i] - 'a']++;
            allFrequencies[t[i] - 'a']--;
        }

        int numberOfMinSteps = 0;
        for (const auto& frequency : allFrequencies)
            numberOfMinSteps += std::max(0, frequency);
        
        return numberOfMinSteps;
    }
};
