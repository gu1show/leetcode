// Link: https://leetcode.com/problems/set-mismatch/
// Runtime: 73 ms
// Memory: 21.2 MB

class Solution 
{
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        
        std::vector<int> duplicateAndRightValue(2);
        duplicateAndRightValue[1] = 1;
        for (int i = 1; i < static_cast<int>(nums.size()); i++)
        {
            if (nums[i] == nums[i - 1])
                duplicateAndRightValue[0] = nums[i];
            else if (nums[i] > nums[i - 1] + 1)
                duplicateAndRightValue[1] = nums[i - 1] + 1;
        }
        
        if (nums[nums.size() - 1] != nums.size())
            duplicateAndRightValue[1] = nums.size();
        
        return duplicateAndRightValue;
    }
};
