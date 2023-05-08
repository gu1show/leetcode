// Link: https://leetcode.com/problems/increasing-triplet-subsequence/
// Runtime: 80 ms
// Memory: 61.7 MB

class Solution 
{
public:
    bool increasingTriplet(const std::vector<int>& nums)
    {
        if (nums.size() < 3) return false;
        else
        {
            int left = nums[0], middle = INT_MAX, i = 1;
            bool hasTriplet = false;
            while ((i < static_cast<int>(nums.size())) && (!hasTriplet))
            {
                if (left > nums[i]) left = nums[i];
                else if ((left < nums[i]) && (middle > nums[i])) middle = nums[i];
                else if (middle < nums[i]) hasTriplet = true;
                i++;
            }
            
            return hasTriplet;
        }
    }
};
