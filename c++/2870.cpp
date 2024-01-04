// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/
// Runtime: 106 ms
// Memory: 85.27 MB

class Solution 
{
public:
    int minOperations(const std::vector<int>& nums) 
    {
        std::unordered_map<int, int> valueAndFrequency;
        for (const auto& val : nums)
            valueAndFrequency[val]++;
        
        int minNumberOfOperations = 0;
        for (const auto&[key, value] : valueAndFrequency)
        {
            if (value == 1) return -1;
            else if (value % 3 == 0) minNumberOfOperations += value / 3;
            else minNumberOfOperations += value / 3 + 1;
        }

        return minNumberOfOperations;
    }
};
