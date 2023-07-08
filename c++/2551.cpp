// Link: https://leetcode.com/problems/put-marbles-in-bags/description/
// Runtime: 207 ms
// Memory: 59.8 MB

class Solution 
{
public:
    long long putMarbles(const std::vector<int>& weights, int k) 
    {
        std::vector<int> pairWeights(weights.size() - 1);
        for (int i = 0; i < static_cast<int>(weights.size() - 1); i++)
            pairWeights[i] = weights[i] + weights[i + 1];
        
        std::sort(pairWeights.begin(), pairWeights.end());

        long long differenceMaximumAndMinimum = 0;
        for (int i = 0; i < k - 1; i++)
            differenceMaximumAndMinimum += pairWeights[static_cast<int>(weights.size()) - i - 2] - pairWeights[i];

        return differenceMaximumAndMinimum;
    }
};
