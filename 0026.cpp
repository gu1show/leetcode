// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
// The first solution
// Runtime: 639 ms
// Memory: 18.4 MB

class Solution 
{
public:
    int removeDuplicates(std::vector<int>& nums) 
    {
        for (int i = 0; i < static_cast<int>(nums.size() - 1); i++) 
        {
            if (nums[i] == nums[i + 1])
            {
                nums.erase(nums.begin() + i);
                i--;
            }
        }

        return nums.size();
    }
};

// The second solution
// Runtime: 16 ms
// Memory: 18.5 MB

class Solution 
{
public:
    int removeDuplicates(std::vector<int>& nums) 
    {
        int i = 0;
        for (int j = 1; j < static_cast<int>(nums.size()); j++) 
        {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};
