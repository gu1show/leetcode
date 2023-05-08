// Link: https://leetcode.com/problems/non-decreasing-array/
// Runtime: 59 ms
// Memory: 27 MB

class Solution
{
public:
    bool checkPossibility(std::vector<int>& nums)
    {
        if (nums.size() < 3) return true;
        else
        {
            short countIncorrect = 0;
            for (int i = 1; i < nums.size(); i++)
                if (nums[i - 1] > nums[i]) 
                {
                    countIncorrect++;
                    
                    if ((i < 2) || (nums[i - 2] <= nums[i]))
                        nums[i - 1] = nums[i];
                    else nums[i] = nums[i - 1];
                }
            
            if (countIncorrect < 2) return true;
            else return false;
        }
    }
};
