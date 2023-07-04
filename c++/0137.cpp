// Link: https://leetcode.com/problems/single-number-ii/description/
// Runtime: 7 ms
// Memory: 9.5 MB

class Solution 
{
public:
    int singleNumber(const std::vector<int>& nums) 
    {
        int ones = 0, twos = 0;
        for (const auto& num : nums)
        {
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }

        return ones;
    }
};
