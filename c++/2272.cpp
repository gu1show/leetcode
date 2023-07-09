// Link: https://leetcode.com/problems/substring-with-largest-variance/description/
// Runtime: 221 ms
// Memory: 6.9 MB

class Solution 
{
public:
    int largestVariance(const std::string& s) 
    {
        std::unordered_map<char, int> counter;
        for (const auto& symbol : s)
            counter[symbol]++;
        
        int largestVariance = 0;
        for (const auto& [major, value] : counter)
        {
            for (const auto& [minor, anotherValue] : counter)
            {
                if (major != minor)
                {
                    int majorCount = 0, minorCount = 0, restMinor = anotherValue;
                    for (const auto& symbol : s)
                    {
                        if (symbol == major) majorCount++;
                        else if (symbol == minor) 
                        {
                            minorCount++;
                            restMinor--;
                        }

                        if (minorCount > 0) 
                            largestVariance = std::max(largestVariance, majorCount - minorCount);
                        
                        if ((majorCount < minorCount) && (restMinor > 0))
                        {
                            majorCount = 0;
                            minorCount = 0;
                        }
                    }
                }
            }
        }

        return largestVariance;
    }
};
