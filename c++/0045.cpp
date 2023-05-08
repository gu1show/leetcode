// Link: https://leetcode.com/problems/jump-game-ii/description/
// Runtime: 15 ms
// Memory: 16.7 MB

class Solution 
{
public:
    int jump(const std::vector<int>& nums) 
    {
        if (nums.size() == 1) return 0;

        int current = 0, max = 0, count = 0, i = 0;
        bool stopJumping = false;
        while ((i < static_cast<int>(nums.size() - 1)) && (!stopJumping))
        {
            max = std::max(max, i + nums[i]);

            if (current == i) 
            {
                current = max;
                count++;
            }

            if (current > nums.size() - 1) stopJumping = true;

            i++;
        }

        return count;
    }
};
