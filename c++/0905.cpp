// Link: https://leetcode.com/problems/sort-array-by-parity/
// The first solution
// Runtime: 91 ms
// Memory: 16.6 MB

class Solution
{
public:
    std::vector<int> sortArrayByParity(const std::vector<int>& nums)
    {
        std::vector<int> result;
        
        for (int value : nums)
            if (value % 2 == 0) result.insert(result.begin(), value);
            else result.insert(result.end(), value);
        
        return result;
    }
};

// The second solution
// Runtime: 16 ms
// Memory: 16.1 MB

class Solution
{
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] % 2 != 0)
            {
                std::swap(nums[left], nums[right]);
                right--;
            }
            else left++;
        }
        
        return nums;
    }
};

// The third solution
// Runtime: 3 ms
// Memory: 16.56 MB

class Solution 
{
public:
    std::vector<int> sortArrayByParity(const std::vector<int>& nums) 
    {
        std::vector<int> sortedNums = nums;
        int left = 0;
        for (int right = 0; right < static_cast<int>(nums.size()); right++)
        {
            if (sortedNums[right] % 2 == 0) 
            {
                std::swap(sortedNums[left], sortedNums[right]);
                left++;
            }
        }

        return sortedNums;
    }
};
