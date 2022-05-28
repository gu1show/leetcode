// Link: https://leetcode.com/problems/missing-number/
// Runtime: 14 ms 
// Memory: 18.1 MB

class Solution 
{
public:
    int missingNumber(const std::vector<int>& nums) 
    {
        int totalSum = nums.size() * (nums.size() + 1) / 2;
        for (int value : nums)
            totalSum -= value;
        return totalSum;
    }
};
