// Link: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/
// Runtime: 19 ms
// Memory: 26.58 MB

class Solution 
{
public:
    int findMaxK(const std::vector<int>& nums) 
    {
        int maxK = -1;
        std::unordered_set<int> values;
        for (const auto& val : nums)
        {
            if ((abs(val) > maxK) && (values.contains(-val)))
                maxK = abs(val);
            values.insert(val);
        }
    
        return maxK;
    }
};
