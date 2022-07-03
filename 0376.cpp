// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// The first solution
// Runtime: 0 ms
// Memory: 7.1 MB

class Solution 
{
public:
    int wiggleMaxLength(const std::vector<int>& nums) 
    {
        int up = 1, down = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1]) down = up + 1;
            else if (nums[i] > nums[i - 1]) up = down + 1;
        }
        return std::max(up, down);
    }
};

// The second solution
// Runtime: 0 ms
// Memory: 7 MB

class Solution 
{
public:
    int wiggleMaxLength(const std::vector<int>& nums) 
    {
        if (nums.size() < 2) return nums.size();
        else
        {
            int previousDifference = nums[1] - nums[0], count = 1;
            if (previousDifference != 0) count = 2;
            for (int i = 2; i < nums.size(); i++)
            {
                int difference = nums[i] - nums[i - 1];
                if (((difference > 0) && (previousDifference <= 0)) ||
                    ((difference < 0) && (previousDifference >= 0)))
                {
                    count++;
                    previousDifference = difference;
                }
            }
                        
            return count;
        }                
    }
};
