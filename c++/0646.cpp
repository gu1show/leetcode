// Link: https://leetcode.com/problems/maximum-length-of-pair-chain/description/
// Runtime: 66 ms
// Memory: 26.02 MB

class Solution 
{
public:
    int findLongestChain(const std::vector<std::vector<int>>& pairs) 
    {
        std::vector<std::vector<int>> sortedPairs = pairs;
        std::sort(sortedPairs.begin(), sortedPairs.end(), [](const auto& a, const auto& b) {return a[1] < b[1];});

        int lengthOfChain = 1, currentRightBorder = sortedPairs[0][1];
        for (int i = 1; i < static_cast<int>(sortedPairs.size()); i++)
            if (currentRightBorder < sortedPairs[i][0])
            {
                lengthOfChain++;
                currentRightBorder = sortedPairs[i][1];
            }
        
        return lengthOfChain;
    }
};
