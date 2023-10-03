// Link: https://leetcode.com/problems/number-of-good-pairs/description/
// Runtime: 0 ms
// Memory: 7.8 MB

class Solution 
{
public:
    int numIdenticalPairs(const std::vector<int>& nums) 
    {
        std::unordered_map<int, int> valueAndFrequency;
        int numberOfGoodPairs = 0;
        for (const auto& val : nums)
        {
            numberOfGoodPairs += valueAndFrequency[val];
            valueAndFrequency[val]++;
        }

        return numberOfGoodPairs;
    }
};
