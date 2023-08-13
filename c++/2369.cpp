// Link: https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/
// Runtime: 120 ms
// Memory: 83.8 MB

class Solution 
{
public:
    bool validPartition(const std::vector<int>& nums) 
    {
        std::vector<bool> canPart(3);
        canPart[0] = true;
        for (int i = 0; i < static_cast<int>(nums.size()); i++)
        {
            bool canPartUpToPosition = false;
            if ((i > 0) && (nums[i] == nums[i - 1])) 
                canPartUpToPosition |= canPart[(i - 1) % 3];
            if ((i > 1) && (nums[i] == nums[i - 1]) && (nums[i] == nums[i - 2])) 
                canPartUpToPosition |= canPart[(i - 2) % 3];
            if ((i > 1) && (nums[i] == nums[i - 1] + 1) && (nums[i] == nums[i - 2] + 2))
                canPartUpToPosition |= canPart[(i - 2) % 3];
            
            canPart[(i + 1) % 3] = canPartUpToPosition;
        }

        return canPart[nums.size() % 3];
    }
};
