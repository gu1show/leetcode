// Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Runtime: 93 ms
// Memory: 42.4 MB

class Solution 
{
public:
    int maxScore(const std::vector<int>& cardPoints, int k) 
    {
        int leftSum = 0;
        for (int i = 0; i < k; i++) leftSum += cardPoints[i];
        
        int windowSum = leftSum;
        int result = leftSum;

        for (int j = k - 1; j > -1; j--)
        {
            windowSum = windowSum - cardPoints[j] + cardPoints[cardPoints.size() + j - k];
            result = std::max(result, windowSum);
        }
        
        return result;
    }
};
